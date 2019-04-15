
int test1()
{
    return 0;
}
int l005BD710;
__declspec(naked) int main()
{
    __asm
    {
;File: Blade_patched.exe
;Path: C:\Games\Severence - Blade of Darkness\Bin\
;Size: 2 187 303
;Type: PE
;Base Of Code: 00001000, Code Size: 001BC000
;Base Of Data: 001BD000, Data Size: 0026A000
;Image Base: 00400000
;Entry Point: 005BC34A
;
;Sections:
;
;   Name   | VirtAddr | VirtSize |  Offset  | PhysSize |  Flags   | Code
;----------+----------+----------+----------+----------+----------+------
; .text    | 00401000 | 001BB94C | 00001000 | 001BC000 | 60000020 |  Yes
; .rdata   | 005BD000 | 0000A072 | 001BD000 | 0000B000 | 40000040 |  
; .data    | 005C8000 | 002280F0 | 001C8000 | 00018000 | C0000040 |  
; .rsrc    | 007F1000 | 000214E8 | 001E0000 | 00022000 | 40000040 |  
; .reloc   | 00813000 | 00013574 | 00202000 | 00014000 | 42000040 |  
;
;Section .text
;
;* Call:
; 00436C15, 00436D7C, 00436EB5, 0043CCEC, 004997BC, 004AD721, 004B0158, 004B0642, 
; 004B13FE, 004B3C1F, 004B3D3B, 004B741E, 004EE3B8, 004EE530, 004EE669, 0053A05F, 
; 0053A1E4, 0053A31D, 00572B9F, 00585B32, 005877BC, 005878F5, 00587AA1, 00587BDA, 
; 0058A52D, 0058A5F7 
;
l00401000: push ebp
l00401001: mov ebp, esp
l00401003: push ecx
l00401004: mov [ebp-0x04], ecx
l00401007: mov eax, [ebp-0x04]
l0040100A: mov dword ptr [eax], 0x00000000
l00401010: mov dword ptr [eax+0x04], 0x00000000
l00401017: mov ecx, [ebp-0x04]
l0040101A: mov dword ptr [ecx+0x08], 0x00000000
l00401021: mov dword ptr [ecx+0x0C], 0x00000000
l00401028: mov edx, [ebp-0x04]
l0040102B: mov dword ptr [edx+0x10], 0x00000000
l00401032: mov dword ptr [edx+0x14], 0x00000000
l00401039: mov eax, [ebp-0x04]
l0040103C: mov dword ptr [eax+0x18], 0x00000000
l00401043: mov dword ptr [eax+0x1C], 0x00000000
l0040104A: mov eax, [ebp-0x04]
l0040104D: mov esp, ebp
l0040104F: pop ebp
l00401050: ret
;
;* Call:
; 0044B311, 004FABF0, 004FB5EB, 004FBD44, 005876B2, 00587997, 00587C7C 
;
l00401051: push ebp
l00401052: mov ebp, esp
l00401054: push ecx
l00401055: push esi
l00401056: push edi
l00401057: mov [ebp-0x04], ecx
l0040105A: mov esi, [ebp+0x08]
l0040105D: mov ecx, 0x00000006
l00401062: mov edi, [ebp-0x04]
l00401065: rep movsd
l00401067: mov eax, [ebp-0x04]
l0040106A: mov ecx, [ebp+0x0C]
l0040106D: mov [eax+0x18], ecx
l00401070: mov edx, [ebp+0x10]
l00401073: mov [eax+0x1C], edx
l00401076: mov eax, [ebp-0x04]
l00401079: pop edi
l0040107A: pop esi
l0040107B: mov esp, ebp
l0040107D: pop ebp
l0040107E: ret 0x000C
;
l00401081: push ebp
l00401082: mov ebp, esp
l00401084: sub esp, 0x00000084
l0040108A: push esi
l0040108B: push edi
l0040108C: mov [ebp-0x00000084], ecx
l00401092: mov eax, [ebp-0x00000084]
l00401098: mov dword ptr [eax], 0x00000000
l0040109E: mov dword ptr [eax+0x04], 0x00000000
l004010A5: mov ecx, [ebp-0x00000084]
l004010AB: mov dword ptr [ecx+0x08], 0x00000000
l004010B2: mov dword ptr [ecx+0x0C], 0x00000000
l004010B9: mov edx, [ebp-0x00000084]
l004010BF: mov dword ptr [edx+0x10], 0x00000000
l004010C6: mov dword ptr [edx+0x14], 0x00000000
l004010CD: mov eax, [ebp+0x08]
l004010D0: push eax
l004010D1: lea ecx, [ebp-0x18]
l004010D4: push ecx
l004010D5: mov ecx, [ebp+0x0C]
l004010D8: call l0x0040A5D0
l004010DD: lea ecx, [ebp-0x18]
l004010E0: call l0x0040A783
l004010E5: fstp qword ptr [ebp-0x20]
l004010E8: mov edx, [ebp+0x08]
l004010EB: mov eax, [ebp+0x0C]
l004010EE: fld qword ptr [edx+0x18]
l004010F1: fadd qword ptr [eax+0x18]
l004010F4: fadd qword ptr [ebp-0x20]
l004010F7: fdiv qword ptr [l005BD710]
l004010FD: mov ecx, [ebp-0x00000084]
l00401103: fstp qword ptr [ecx+0x18]
l00401106: mov edx, [ebp-0x00000084]
l0040110C: mov eax, [ebp+0x08]
l0040110F: fld qword ptr [edx+0x18]
l00401112: fcomp qword ptr [eax+0x18]
l00401115: fstsw ax
l00401117: test ah, 0x01
l0040111A: je  0x00401146
l0040111C: mov ecx, [ebp+0x08]
l0040111F: mov edx, [ebp-0x00000084]
l00401125: mov eax, [ecx+0x18]
l00401128: mov [edx+0x18], eax
l0040112B: mov ecx, [ecx+0x1C]
l0040112E: mov [edx+0x1C], ecx
l00401131: mov esi, [ebp+0x08]
l00401134: mov ecx, 0x00000006
l00401139: mov edi, [ebp-0x00000084]
l0040113F: rep movsd
l00401141: jmp l0x004011F4
;
;* Jump:
; 0040111A(C) 
;
l00401146: mov edx, [ebp-0x00000084]
l0040114C: mov eax, [ebp+0x0C]
l0040114F: fld qword ptr [edx+0x18]
l00401152: fcomp qword ptr [eax+0x18]
l00401155: fstsw ax
l00401157: test ah, 0x01
l0040115A: je  0x00401183
l0040115C: mov ecx, [ebp+0x0C]
l0040115F: mov edx, [ebp-0x00000084]
l00401165: mov eax, [ecx+0x18]
l00401168: mov [edx+0x18], eax
l0040116B: mov ecx, [ecx+0x1C]
l0040116E: mov [edx+0x1C], ecx
l00401171: mov esi, [ebp+0x0C]
l00401174: mov ecx, 0x00000006
l00401179: mov edi, [ebp-0x00000084]
l0040117F: rep movsd
l00401181: jmp l0x004011F4
;
;* Jump:
; 0040115A(C) 
;
l00401183: mov edx, [ebp-0x1C]
l00401186: push edx
l00401187: mov eax, [ebp-0x20]
l0040118A: push eax
l0040118B: lea ecx, [ebp-0x18]
l0040118E: call l0x0040A4CE
l00401193: lea ecx, [ebp-0x18]
l00401196: push ecx
l00401197: mov edx, [ebp-0x00000084]
l0040119D: mov eax, [edx+0x1C]
l004011A0: push eax
l004011A1: mov ecx, [edx+0x18]
l004011A4: push ecx
l004011A5: lea edx, [ebp-0x68]
l004011A8: push edx
l004011A9: call l0x0040A375
l004011AE: add esp, 0x00000010
l004011B1: push eax
l004011B2: lea eax, [ebp-0x80]
l004011B5: push eax
l004011B6: lea ecx, [ebp-0x18]
l004011B9: push ecx
l004011BA: mov edx, [ebp+0x08]
l004011BD: mov eax, [edx+0x1C]
l004011C0: push eax
l004011C1: mov ecx, [edx+0x18]
l004011C4: push ecx
l004011C5: lea edx, [ebp-0x38]
l004011C8: push edx
l004011C9: call l0x0040A375
l004011CE: add esp, 0x00000010
l004011D1: push eax
l004011D2: lea eax, [ebp-0x50]
l004011D5: push eax
l004011D6: mov ecx, [ebp+0x08]
l004011D9: call l0x0040A5D0
l004011DE: mov ecx, eax
l004011E0: call l0x0040A567
l004011E5: mov esi, eax
l004011E7: mov ecx, 0x00000006
l004011EC: mov edi, [ebp-0x00000084]
l004011F2: rep movsd
;
;* Jump:
; 00401141(U), 00401181(U) 
;
l004011F4: mov eax, [ebp-0x00000084]
l004011FA: pop edi
l004011FB: pop esi
l004011FC: mov esp, ebp
l004011FE: pop ebp
l004011FF: ret 0x0008
;
    }
}

