
int test1()
{
    return 0;
}
int l005BD710;
int l005BD77C;
__declspec(naked) int main()
{
    __asm
    {
;l00401000: push ebp
           mov ebp, esp
           push ecx
           mov [ebp-004h], ecx
           mov eax, [ebp-004h]
;           dd l00401000
;           dd last
;           dd lab
;           db 06
;           db 07
;last:      mov eax, [ebp-00Ch]
;           lab db 05
           or eax, 0FFFFFFFFh

    }
}