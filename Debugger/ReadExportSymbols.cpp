#include <map>
#include "ReadExportSymbols.h"

void ReadNullTerminatedString(
    HANDLE hProcess, LPVOID address, char* buffer, DWORD size)
{
    for (DWORD i = 0; i < size; i++)
    {
        ReadProcessMemory(
            hProcess,
            (char*)address + i,
            buffer + i, 1, nullptr);
        if (buffer[i] == '\0')
            return;
    }
    buffer[size - 1] = '\0';
}

std::map<LPVOID, std::string> ReadExportSymbols(
    HANDLE hProcess,
    char* baseAddr,
    Dumper& dumper)
{
    // Based on http://www.rohitab.com/discuss/topic/38615-getprocaddress-replacement/
    std::map<LPVOID, std::string> symbols;
    IMAGE_DOS_HEADER dosHeader;
    ReadProcessMemory(
        hProcess,
        baseAddr,
        &dosHeader, sizeof(dosHeader), nullptr);
    IMAGE_NT_HEADERS ntHeaders;
    ReadProcessMemory(
        hProcess,
        baseAddr + dosHeader.e_lfanew,
        &ntHeaders, sizeof(ntHeaders), nullptr);
    IMAGE_OPTIONAL_HEADER* optHeader = &ntHeaders.OptionalHeader;
    IMAGE_DATA_DIRECTORY* exp_entry = (IMAGE_DATA_DIRECTORY*)
        (&optHeader->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT]);
    IMAGE_EXPORT_DIRECTORY exp_dir;
    ReadProcessMemory(
        hProcess,
        baseAddr + exp_entry->VirtualAddress,
        &exp_dir, sizeof(exp_dir), nullptr);
    void** func_table = new void* [exp_dir.NumberOfFunctions];
    ReadProcessMemory(
        hProcess,
        baseAddr + exp_dir.AddressOfFunctions,
        func_table, sizeof(void*) * exp_dir.NumberOfFunctions, nullptr);
    WORD* ord_table = new WORD[exp_dir.NumberOfNames];
    ReadProcessMemory(
        hProcess,
        baseAddr + exp_dir.AddressOfNameOrdinals,
        ord_table, sizeof(WORD) * exp_dir.NumberOfNames, nullptr);
    char** name_table = new char* [exp_dir.NumberOfNames];
    ReadProcessMemory(
        hProcess,
        baseAddr + exp_dir.AddressOfNames,
        name_table, sizeof(char*) * exp_dir.NumberOfNames, nullptr);
    void* address = NULL;
    DWORD i;
    /* import by name */
    for (i = 0; i < exp_dir.NumberOfNames; i++) {
        /* name table pointers are rvas */
        DWORD name_rva = (DWORD)name_table[i];
        if (ord_table[i] >= exp_dir.NumberOfFunctions)
            continue;
        DWORD address_rva = (DWORD)func_table[ord_table[i]];
        auto address = baseAddr + address_rva;
        char name[256];
        ReadNullTerminatedString(
            hProcess,
            baseAddr + name_rva,
            name, sizeof(name));
        /* is forwarded? */
        if ((char*)address >= (char*)baseAddr + exp_entry->VirtualAddress &&
            (char*)address < (char*)baseAddr + exp_entry->VirtualAddress +
            exp_entry->Size)
        {

            char dll_name[256];
            ReadNullTerminatedString(
                hProcess, address, dll_name, sizeof(dll_name));
            auto func_name = strchr(dll_name, '.');
            *func_name++ = '\0';
            dumper.Printf(
                Dumper::Level::Debug,
                "Unsupported forwarded function %s!%s\n",
                dll_name,
                func_name);
            continue;
        }
        symbols[address] = name;
    }
    delete[] func_table;
    delete[] ord_table;
    delete[] name_table;
    return symbols;
}