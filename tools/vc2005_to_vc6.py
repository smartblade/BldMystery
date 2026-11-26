#!/usr/bin/env python3
"""Convert Visual Studio 2005 solution (.sln) and projects (.vcproj)
to Visual C++ 6.0 workspace (.dsw) and projects (.dsp).

Usage:
    python tools/vc2005_to_vc6.py src/BOD.sln
"""
import argparse
import ntpath
import os
import re
import xml.etree.ElementTree as ET

DOLLAR = chr(36)
OPEN_BRACES = chr(123) * 3
CLOSE_BRACES = chr(125) * 3

CONFIG_TYPES = {
    "1": ("Win32 (x86) Application", "0x0101"),
    "2": ("Win32 (x86) Dynamic-Link Library", "0x0102"),
    "4": ("Win32 (x86) Static Library", "0x0104"),
}

RUNTIME_FLAGS = {
    "0": "/MT",
    "1": "/MTd",
    "2": "/MD",
    "3": "/MDd",
    "4": "/ML",
    "5": "/MLd",
}

INLINE_FUNCTION_EXPANSION_FLAGS = {
    "0": "/Ob0",
    "1": "/Ob1",
    "2": "/Ob2",
}

OPTIMIZATION_FLAGS = {
    "0": "/Od",
    "1": "/O1",
    "2": "/O2",
    "3": "/Ox",
}

STRUCT_ALIGNMENT_FLAGS = {
    "1": "/Zp1",
    "2": "/Zp2",
    "3": "/Zp4",
    "4": "/Zp8",
    "5": "/Zp16",
}

IGNORED_DEFINES = {
    "_CRT_SECURE_NO_DEPRECATE",
    "_CRT_NONSTDC_NO_DEPRECATE",
    "WINDOWS_IGNORE_PACKING_MISMATCH",
}


def parse_sln(sln_path):
    with open(sln_path, "r", encoding="utf-8-sig") as f:
        text = f.read()

    projects = {}
    project_order = []

    proj_re = re.compile(
        r'Project\("\{[^}]+\}"\)\s*=\s*"([^"]+)",\s*"([^"]+)",\s*"(\{[^}]+\})"(.*?)\bEndProject\b',
        re.DOTALL,
    )
    dep_re = re.compile(
        r'ProjectSection\(ProjectDependencies\)\s*=\s*postProject(.*?)EndProjectSection',
        re.DOTALL,
    )
    guid_re = re.compile(r'(\{[0-9A-Fa-f-]+\})\s*=')

    for match in proj_re.finditer(text):
        name, rel_path, guid, body = match.groups()
        guid = guid.upper()
        deps = []
        dep_match = dep_re.search(body)
        if dep_match:
            deps = [g.upper() for g in guid_re.findall(dep_match.group(1))]
        projects[guid] = {
            "name": name,
            "vcproj": rel_path.replace("/", "\\"),
            "guid": guid,
            "deps": deps,
        }
        project_order.append(guid)

    return projects, project_order


def split_list(val):
    if not val:
        return []
    parts = []
    for item in val.replace(",", ";").split(";"):
        item = item.strip().strip('"')
        if item:
            parts.append(item)
    return parts


def split_space_list(val):
    if not val:
        return []
    return [item.strip().strip('"') for item in val.split() if item.strip()]


def resolve_macros(path_str, sln_rel_from_dsp, config_name, macros=None):
    """Replace the macros of Visual Studio 2005, VC6 has none of them."""
    if not path_str:
        return ""
    res = path_str.replace(DOLLAR + "(SolutionDir)", sln_rel_from_dsp)
    res = res.replace(DOLLAR + "(ConfigurationName)", config_name)
    for name, value in (macros or {}).items():
        res = res.replace(DOLLAR + "(" + name + ")", value)
    res = res.replace("/", "\\")
    while "\\\\" in res:
        res = res.replace("\\\\", "\\")
    return res.rstrip("\\") if len(res) > 3 else res


def build_compiler_flags(tool, config_name, is_debug, is_dll):
    flags = ["/nologo"]

    rt = tool.get("RuntimeLibrary", "2" if not is_debug else "3")
    flags.append(RUNTIME_FLAGS.get(rt, "/MD"))

    wl = tool.get("WarningLevel", "3")
    if wl in ("0", "1", "2", "3", "4"):
        flags.append(f"/W{wl}")

    dbg = tool.get("DebugInformationFormat", "0")
    if dbg == "1":
        flags.append("/Z7")
    elif dbg == "3":
        flags.append("/Zi")
    elif dbg == "4":
        flags.append("/ZI")

    opt = tool.get("Optimization", "0" if is_debug else "2")
    flags.append(OPTIMIZATION_FLAGS.get(opt, "/Od"))

    inline = tool.get("InlineFunctionExpansion", "")
    if inline in INLINE_FUNCTION_EXPANSION_FLAGS:
        flags.append(INLINE_FUNCTION_EXPANSION_FLAGS[inline])

    if tool.get("EnableIntrinsicFunctions", "").lower() == "true":
        flags.append("/Oi")

    align = tool.get("StructMemberAlignment", "0")
    if align in STRUCT_ALIGNMENT_FLAGS:
        flags.append(STRUCT_ALIGNMENT_FLAGS[align])

    eh = tool.get("ExceptionHandling", "1")
    if eh != "0":
        flags.append("/GX")

    if tool.get("RuntimeTypeInfo", "").lower() == "true":
        flags.append("/GR")

    for inc in split_list(tool.get("AdditionalIncludeDirectories", "")):
        flags.append(f'/I "{inc}"')

    defines = [
        d for d in split_list(tool.get("PreprocessorDefinitions", ""))
        if d not in IGNORED_DEFINES
    ]
    if is_dll and "_USRDLL" not in defines and "_WINDLL" not in defines:
        defines.append("_USRDLL")
    for d in defines:
        flags.append(f'/D "{d}"')

    pch = tool.get("UsePrecompiledHeader", "0")
    pch_header = tool.get("PrecompiledHeaderThrough", "stdafx.h")
    if pch == "1":
        flags.append(f'/Yc"{pch_header}"')
    elif pch == "2":
        flags.append(f'/Yu"{pch_header}"')
    else:
        flags.append("/YX")

    flags.append("/FD")
    if is_debug:
        flags.append("/GZ")
    flags.append("/c")
    return " ".join(flags)


def build_linker_flags(
    tool, project_name, is_debug, is_dll, sln_rel_from_dsp, config_name, macros
):
    flags = []
    deps = split_space_list(tool.get("AdditionalDependencies", ""))
    default_libs = [
        "kernel32.lib", "user32.lib", "gdi32.lib", "winspool.lib",
        "comdlg32.lib", "advapi32.lib", "shell32.lib", "ole32.lib",
        "oleaut32.lib", "uuid.lib", "odbc32.lib", "odbccp32.lib",
    ]
    for lib in default_libs + deps:
        if lib not in flags:
            flags.append(lib)

    flags.append("/nologo")

    subsys = tool.get("SubSystem", "2")
    if is_dll:
        flags.append("/dll")
    elif subsys == "1":
        flags.append("/subsystem:console")
    else:
        flags.append("/subsystem:windows")

    if is_debug:
        flags.append("/incremental:yes")
    else:
        flags.append("/incremental:no")

    if tool.get("GenerateDebugInformation", "").lower() == "true":
        flags.append("/debug")

    flags.append("/machine:I386")

    for lib_dir in split_list(tool.get("AdditionalLibraryDirectories", "")):
        resolved = resolve_macros(
            lib_dir, sln_rel_from_dsp, config_name, macros)
        flags.append(f'/libpath:"{resolved}"')

    for ign in split_list(tool.get("IgnoreDefaultLibraryNames", "")):
        flags.append(f'/nodefaultlib:"{ign}"')

    def_file = tool.get("ModuleDefinitionFile", "")
    if def_file:
        flags.append(f'/def:"{def_file}"')

    out_file = tool.get("OutputFile", "")
    if out_file:
        resolved_out = resolve_macros(
            out_file, sln_rel_from_dsp, config_name, macros)
        flags.append(f'/out:"{resolved_out}"')

    imp_lib = tool.get("ImportLibrary", "")
    if imp_lib:
        resolved_imp = resolve_macros(
            imp_lib, sln_rel_from_dsp, config_name, macros)
        flags.append(f'/implib:"{resolved_imp}"')

    return " ".join(flags)


def parse_vcproj(vcproj_path, sln_dir):
    tree = ET.parse(vcproj_path)
    root = tree.getroot()
    project_name = root.get("Name")
    dsp_dir = os.path.dirname(os.path.abspath(vcproj_path))
    sln_rel = os.path.relpath(sln_dir, dsp_dir)
    sln_rel_prefix = ".\\" if sln_rel == "." else sln_rel.replace("/", "\\") + "\\"

    configs = []
    for cfg_el in root.findall("./Configurations/Configuration"):
        full_name = cfg_el.get("Name")
        cfg_short = full_name.split("|").pop(0)
        vc6_cfg_name = f"{project_name} - Win32 {cfg_short}"
        cfg_type = cfg_el.get("ConfigurationType", "1")
        is_debug = "debug" in cfg_short.lower()
        is_dll = cfg_type == "2"

        names = {"ProjectName": project_name, "TargetName": project_name}
        out_dir = resolve_macros(
            cfg_el.get("OutputDirectory", cfg_short), sln_rel_prefix, cfg_short,
            names
        )
        int_dir = resolve_macros(
            cfg_el.get("IntermediateDirectory", cfg_short), sln_rel_prefix,
            cfg_short, names
        )
        macros = dict(names, OutDir=out_dir, IntDir=int_dir)

        tools = {t.get("Name"): t for t in cfg_el.findall("./Tool")}
        cl_tool = tools.get("VCCLCompilerTool", ET.Element("Tool"))
        link_tool = tools.get("VCLinkerTool", ET.Element("Tool"))
        rsc_tool = tools.get("VCResourceCompilerTool", ET.Element("Tool"))
        masm_tool = tools.get("MASM", ET.Element("Tool"))

        cl_flags = build_compiler_flags(cl_tool, cfg_short, is_debug, is_dll)
        if cfg_type == "4":
            link_flags = "/nologo"
        else:
            link_flags = build_linker_flags(
                link_tool, project_name, is_debug, is_dll, sln_rel_prefix,
                cfg_short, macros
            )

        rsc_incs = split_list(cl_tool.get("AdditionalIncludeDirectories", "")) + split_list(
            rsc_tool.get("AdditionalIncludeDirectories", "")
        )
        rsc_flags = " ".join(["/l 0x409"] + [f'/i "{inc}"' for inc in dict.fromkeys(rsc_incs)])

        masm_inc = masm_tool.get("IncludePaths", "")

        configs.append({
            "full_name": full_name,
            "short_name": cfg_short,
            "vc6_name": vc6_cfg_name,
            "type": cfg_type,
            "is_debug": is_debug,
            "out_dir": out_dir,
            "int_dir": int_dir,
            "cl_flags": cl_flags,
            "link_flags": link_flags,
            "rsc_flags": rsc_flags,
            "masm_inc": masm_inc,
        })

    def parse_files_node(parent_el):
        items = []
        for child in parent_el:
            if child.tag == "Filter":
                items.append({
                    "kind": "filter",
                    "name": child.get("Name", "Files"),
                    "filter": child.get("Filter", ""),
                    "children": parse_files_node(child),
                })
            elif child.tag == "File":
                rel_path = child.get("RelativePath", "").replace("/", "\\")
                file_cfgs = {}
                for fc in child.findall("./FileConfiguration"):
                    fc_name = fc.get("Name")
                    excluded = fc.get("ExcludedFromBuild", "").lower() == "true"
                    fc_cl = fc.find("./Tool[@Name='VCCLCompilerTool']")
                    extra_flags = []
                    if fc_cl is not None:
                        for inc in split_list(fc_cl.get("AdditionalIncludeDirectories", "")):
                            extra_flags.append(f'/I "{inc}"')
                        for d in split_list(fc_cl.get("PreprocessorDefinitions", "")):
                            if d not in IGNORED_DEFINES:
                                extra_flags.append(f'/D "{d}"')
                    file_cfgs[fc_name] = {
                        "excluded": excluded,
                        "extra_flags": " ".join(extra_flags),
                    }
                items.append({
                    "kind": "file",
                    "path": rel_path,
                    "configs": file_cfgs,
                })
        return items

    files_root = root.find("./Files")
    tree_items = parse_files_node(files_root) if files_root is not None else []
    return project_name, configs, tree_items

def generate_dsp(project_name, configs, tree_items):
    first_cfg = configs[0] if configs else None

    first_type = first_cfg["type"] if first_cfg else "1"
    target_desc, target_hex = CONFIG_TYPES.get(
        first_type, CONFIG_TYPES["1"]
    )
    default_cfg = first_cfg["vc6_name"] if first_cfg else f"{project_name} - Win32 Release"
    cfg_macro = DOLLAR + "(CFG)"

    lines = [
        f'# Microsoft Developer Studio Project File - Name="{project_name}" - Package Owner=<4>',
        "# Microsoft Developer Studio Generated Build File, Format Version 6.00",
        "# ** DO NOT EDIT **",
        "",
        f'# TARGTYPE "{target_desc}" {target_hex}',
        "",
        f"CFG={default_cfg}",
        "!MESSAGE This is not a valid makefile. To build this project using NMAKE,",
        "!MESSAGE use the Export Makefile command and run",
        "!MESSAGE ",
        f'!MESSAGE NMAKE /f "{project_name}.mak".',
        "!MESSAGE ",
        "!MESSAGE You can specify a configuration when running NMAKE",
        "!MESSAGE by defining the macro CFG on the command line. For example:",
        "!MESSAGE ",
        f'!MESSAGE NMAKE /f "{project_name}.mak" CFG="{default_cfg}"',
        "!MESSAGE ",
        "!MESSAGE Possible choices for configuration are:",
        "!MESSAGE ",
    ]

    for cfg in configs:
        t_desc, _ = CONFIG_TYPES.get(cfg["type"], CONFIG_TYPES["1"])
        lines.append(f'!MESSAGE "{cfg["vc6_name"]}" (based on "{t_desc}")')

    lines.extend([
        "!MESSAGE ",
        "",
        "# Begin Project",
        "# PROP AllowPerConfigDependencies 0",
        '# PROP Scc_ProjName ""',
        '# PROP Scc_LocalPath ""',
        "CPP=cl.exe",
        "MTL=midl.exe",
        "RSC=rc.exe",
        "",
    ])

    for idx, cfg in enumerate(configs):
        cond = "!IF" if idx == 0 else "!ELSEIF"
        use_debug_libs = "1" if cfg["is_debug"] else "0"
        lines.extend([
            f'{cond}  "{cfg_macro}" == "{cfg["vc6_name"]}"',
            "",
            "# PROP BASE Use_MFC 0",
            f"# PROP BASE Use_Debug_Libraries {use_debug_libs}",
            f'# PROP BASE Output_Dir "{cfg["out_dir"]}"',
            f'# PROP BASE Intermediate_Dir "{cfg["int_dir"]}"',
            '# PROP BASE Target_Dir ""',
            "# PROP Use_MFC 0",
            f"# PROP Use_Debug_Libraries {use_debug_libs}",
            f'# PROP Output_Dir "{cfg["out_dir"]}"',
            f'# PROP Intermediate_Dir "{cfg["int_dir"]}"',
            "# PROP Ignore_Export_Lib 0",
            '# PROP Target_Dir ""',
            f"# ADD BASE CPP {cfg['cl_flags']}",
            f"# ADD CPP {cfg['cl_flags']}",
            "# ADD BASE MTL /nologo /mktyplib203 /win32",
            "# ADD MTL /nologo /mktyplib203 /win32",
            f"# ADD BASE RSC {cfg['rsc_flags']}",
            f"# ADD RSC {cfg['rsc_flags']}",
            "BSC32=bscmake.exe",
            "# ADD BASE BSC32 /nologo",
            "# ADD BSC32 /nologo",
        ])
        if cfg["type"] == "4":
            lines.extend([
                "LIB32=link.exe -lib",
                f"# ADD BASE LIB32 {cfg['link_flags']}",
                f"# ADD LIB32 {cfg['link_flags']}",
            ])
        else:
            lines.extend([
                "LINK32=link.exe",
                f"# ADD BASE LINK32 {cfg['link_flags']}",
                f"# ADD LINK32 {cfg['link_flags']}",
            ])
        lines.append("")

    lines.extend([
        "!ENDIF ",
        "",
        "# Begin Target",
        "",
    ])
    for cfg in configs:
        lines.append(f'# Name "{cfg["vc6_name"]}"')

    int_dir_m = DOLLAR + "(IntDir)"
    int_dir_up = DOLLAR + "(INTDIR)"
    out_dir_up = DOLLAR + "(OUTDIR)"
    in_path_m = DOLLAR + "(InputPath)"
    in_name_m = DOLLAR + "(InputName)"
    src_m = DOLLAR + "(SOURCE)"

    def emit_items(items):
        for item in items:
            if item["kind"] == "filter":
                lines.append(f'# Begin Group "{item["name"]}"')
                lines.append("")
                lines.append(f'# PROP Default_Filter "{item["filter"]}"')
                emit_items(item["children"])
                lines.append("# End Group")
            elif item["kind"] == "file":
                path = item["path"]
                is_asm = path.lower().endswith(".asm")
                has_per_cfg = bool(item["configs"]) or is_asm

                lines.append("# Begin Source File")
                lines.append("")
                lines.append(f"SOURCE={path}")

                if has_per_cfg:
                    lines.append("")
                    for idx, cfg in enumerate(configs):
                        cond = "!IF" if idx == 0 else "!ELSEIF"
                        lines.append(f'{cond}  "{cfg_macro}" == "{cfg["vc6_name"]}"')
                        lines.append("")
                        fc = item["configs"].get(cfg["full_name"], {})
                        if fc.get("excluded"):
                            lines.append("# PROP Exclude_From_Build 1")
                        elif fc.get("extra_flags"):
                            lines.append(f"# ADD CPP {fc['extra_flags']}")
                        elif is_asm:
                            inc_arg = f'/I"{cfg["masm_inc"]}" ' if cfg["masm_inc"] else ""
                            input_name, _ = ntpath.splitext(
                                ntpath.basename(path))
                            obj_target = f'"{int_dir_m}\\{in_name_m}.obj"'
                            lines.extend([
                                f"# Begin Custom Build - Assembling {in_path_m}...",
                                "IntDir=.\\" + cfg["int_dir"],
                                "InputPath=" + path,
                                "InputName=" + input_name,
                                "",
                                f'{obj_target} : {src_m} "{int_dir_up}" "{out_dir_up}"',
                                f'\tml /c /coff /Cx {inc_arg}/Fo{obj_target} "{in_path_m}"',
                                "",
                                "# End Custom Build",
                            ])
                        lines.append("")
                    lines.append("!ENDIF ")
                    lines.append("")

                lines.append("# End Source File")

    emit_items(tree_items)

    lines.extend([
        "# End Target",
        "# End Project",
        "",
    ])
    return "\r\n".join(lines)


def generate_dsw(projects, project_order):
    lines = [
        "Microsoft Developer Studio Workspace File, Format Version 6.00",
        "# WARNING: DO NOT EDIT OR DELETE THIS WORKSPACE FILE!",
        "",
    ]

    for guid in project_order:
        proj = projects[guid]
        vcproj_base, _ = os.path.splitext(proj["vcproj"])
        dsp_rel = ".\\" + vcproj_base + ".dsp"
        lines.extend([
            "#" * 79,
            "",
            f'Project: "{proj["name"]}"="{dsp_rel}" - Package Owner=<4>',
            "",
            "Package=<5>",
            OPEN_BRACES,
            CLOSE_BRACES,
            "",
            "Package=<4>",
            OPEN_BRACES,
        ])
        for dep_guid in proj["deps"]:
            if dep_guid in projects:
                lines.extend([
                    "    Begin Project Dependency",
                    f"    Project_Dep_Name {projects[dep_guid]['name']}",
                    "    End Project Dependency",
                ])
        lines.extend([
            CLOSE_BRACES,
            "",
        ])

    lines.extend([
        "#" * 79,
        "",
        "Global:",
        "",
        "Package=<5>",
        OPEN_BRACES,
        CLOSE_BRACES,
        "",
        "Package=<3>",
        OPEN_BRACES,
        CLOSE_BRACES,
        "",
        "#" * 79,
        "",
    ])
    return "\r\n".join(lines)


def main():
    parser = argparse.ArgumentParser(
        description="Convert VS 2005 .sln/.vcproj to Visual C++ 6.0 .dsw/.dsp"
    )
    parser.add_argument("sln", help="Path to .sln file (e.g. src/BOD.sln)")
    args = parser.parse_args()

    sln_path = os.path.abspath(args.sln)
    sln_dir = os.path.dirname(sln_path)
    projects, project_order = parse_sln(sln_path)

    for guid in project_order:
        proj = projects[guid]
        vcproj_abs = os.path.join(sln_dir, proj["vcproj"].replace("\\", os.sep))
        if not os.path.isfile(vcproj_abs):
            print(f"Warning: {vcproj_abs} not found, skipping.")
            continue
        name, configs, tree_items = parse_vcproj(vcproj_abs, sln_dir)
        vcproj_base, _ = os.path.splitext(vcproj_abs)
        dsp_abs = vcproj_base + ".dsp"
        dsp_content = generate_dsp(name, configs, tree_items)
        with open(dsp_abs, "wb") as f:
            f.write(dsp_content.encode("windows-1251", errors="replace"))
        print(f"Generated: {dsp_abs}")

    sln_base, _ = os.path.splitext(sln_path)
    dsw_abs = sln_base + ".dsw"
    dsw_content = generate_dsw(projects, project_order)
    with open(dsw_abs, "wb") as f:
        f.write(dsw_content.encode("windows-1251", errors="replace"))
    print(f"Generated: {dsw_abs}")


if __name__ == "__main__":
    main()
