# Plasticity 1.4.10

Mainly is about ptching pk.node and change instruction:
```
.text:00000001800701E9 48 C7 47 08 00 00 00 00                 mov     qword ptr [rdi+8], 0 ;
```
to
```
.text:00000001800701E9 48 C7 47 08 01 00 00 00                 mov     qword ptr [rdi+8], 1 ;
```

Check closer below code. This function is checking if "STUDIO_FEATURES" are granted. Normally with trial license only "TRIAL_FEATURES" are granted.

pk.node module from D:\Plasticity\app-1.4.10\resources\app\.webpack\renderer
```
.text:0000000180070140                         sub_180070140   proc near               ; CODE XREF: sub_1800062BC↑j
.text:0000000180070140                                                                 ; DATA XREF: .pdata:0000000180B49A6C↓o
.text:0000000180070140
.text:0000000180070140                         arg_0           = qword ptr  8
.text:0000000180070140                         arg_8           = qword ptr  10h
.text:0000000180070140                         arg_10          = qword ptr  18h
.text:0000000180070140
.text:0000000180070140 48 89 5C 24 18                          mov     [rsp+arg_10], rbx
.text:0000000180070145 56                                      push    rsi
.text:0000000180070146 57                                      push    rdi
.text:0000000180070147 41 56                                   push    r14
.text:0000000180070149 48 83 EC 20                             sub     rsp, 20h
.text:000000018007014D 4C 8B 71 30                             mov     r14, [rcx+30h]
.text:0000000180070151 49 8B F0                                mov     rsi, r8
.text:0000000180070154 48 8B 41 08                             mov     rax, [rcx+8]
.text:0000000180070158 4D 23 F1                                and     r14, r9
.text:000000018007015B 49 C1 E6 04                             shl     r14, 4
.text:000000018007015F 48 8B FA                                mov     rdi, rdx
.text:0000000180070162 4C 03 71 18                             add     r14, [rcx+18h]
.text:0000000180070166 49 8B 5E 08                             mov     rbx, [r14+8]
.text:000000018007016A 48 3B D8                                cmp     rbx, rax
.text:000000018007016D 75 1C                                   jnz     short loc_18007018B
.text:000000018007016F 48 89 02                                mov     [rdx], rax
.text:0000000180070172 48 8B C2                                mov     rax, rdx
.text:0000000180070175 48 C7 42 08 00 00 00 00                 mov     qword ptr [rdx+8], 0
.text:000000018007017D 48 8B 5C 24 50                          mov     rbx, [rsp+38h+arg_10]
.text:0000000180070182 48 83 C4 20                             add     rsp, 20h
.text:0000000180070186 41 5E                                   pop     r14
.text:0000000180070188 5F                                      pop     rdi
.text:0000000180070189 5E                                      pop     rsi
.text:000000018007018A C3                                      retn
.text:000000018007018B                         ; ---------------------------------------------------------------------------
.text:000000018007018B
.text:000000018007018B                         loc_18007018B:                          ; CODE XREF: sub_180070140+2D↑j
.text:000000018007018B 4D 8B 36                                mov     r14, [r14]
.text:000000018007018E 48 89 6C 24 40                          mov     [rsp+38h+arg_0], rbp
.text:0000000180070193 49 8B 68 10                             mov     rbp, [r8+10h]
.text:0000000180070197 4C 89 7C 24 48                          mov     [rsp+38h+arg_8], r15
.text:000000018007019C 4D 8B 78 18                             mov     r15, [r8+18h]
.text:00000001800701A0
.text:00000001800701A0                         loc_1800701A0:                          ; CODE XREF: sub_180070140+98↓j
.text:00000001800701A0 48 83 7B 28 10                          cmp     qword ptr [rbx+28h], 10h
.text:00000001800701A5 48 8D 53 10                             lea     rdx, [rbx+10h]
.text:00000001800701A9 48 8B 42 10                             mov     rax, [rdx+10h]
.text:00000001800701AD 72 03                                   jb      short loc_1800701B2
.text:00000001800701AF 48 8B 12                                mov     rdx, [rdx]      ; Buf2
.text:00000001800701B2
.text:00000001800701B2                         loc_1800701B2:                          ; CODE XREF: sub_180070140+6D↑j
.text:00000001800701B2 48 8B CE                                mov     rcx, rsi
.text:00000001800701B5 49 83 FF 10                             cmp     r15, 10h
.text:00000001800701B9 72 03                                   jb      short loc_1800701BE
.text:00000001800701BB 48 8B 0E                                mov     rcx, [rsi]      ; Buf1
.text:00000001800701BE
.text:00000001800701BE                         loc_1800701BE:                          ; CODE XREF: sub_180070140+79↑j
.text:00000001800701BE 48 3B E8                                cmp     rbp, rax
.text:00000001800701C1 75 0C                                   jnz     short loc_1800701CF
.text:00000001800701C3 4C 8B C5                                mov     r8, rbp         ; Size
.text:00000001800701C6 E8 8A 81 F9 FF                          call    j_memcmp
.text:00000001800701CB 85 C0                                   test    eax, eax
.text:00000001800701CD 74 0B                                   jz      short loc_1800701DA
.text:00000001800701CF
.text:00000001800701CF                         loc_1800701CF:                          ; CODE XREF: sub_180070140+81↑j
.text:00000001800701CF 49 3B DE                                cmp     rbx, r14
.text:00000001800701D2 74 12                                   jz      short loc_1800701E6
.text:00000001800701D4 48 8B 5B 08                             mov     rbx, [rbx+8]
.text:00000001800701D8 EB C6                                   jmp     short loc_1800701A0
.text:00000001800701DA                         ; ---------------------------------------------------------------------------
.text:00000001800701DA
.text:00000001800701DA                         loc_1800701DA:                          ; CODE XREF: sub_180070140+8D↑j
.text:00000001800701DA 48 8B 03                                mov     rax, [rbx]
.text:00000001800701DD 48 89 07                                mov     [rdi], rax
.text:00000001800701E0 48 89 5F 08                             mov     [rdi+8], rbx
.text:00000001800701E4 EB 0B                                   jmp     short loc_1800701F1
.text:00000001800701E6                         ; ---------------------------------------------------------------------------
.text:00000001800701E6
.text:00000001800701E6                         loc_1800701E6:                          ; CODE XREF: sub_180070140+92↑j
.text:00000001800701E6 48 89 1F                                mov     [rdi], rbx
.text:00000001800701E9 48 C7 47 08 00 00 00 00                 mov     qword ptr [rdi+8], 0 ;    <----------------- put 1 here, change 00 00 00 00 to 01 00 00 00
.text:00000001800701F1
.text:00000001800701F1                         loc_1800701F1:                          ; CODE XREF: sub_180070140+A4↑j
.text:00000001800701F1 48 8B 6C 24 40                          mov     rbp, [rsp+38h+arg_0]
.text:00000001800701F6 48 8B C7                                mov     rax, rdi
.text:00000001800701F9 4C 8B 7C 24 48                          mov     r15, [rsp+38h+arg_8]
.text:00000001800701FE 48 8B 5C 24 50                          mov     rbx, [rsp+38h+arg_10]
.text:0000000180070203 48 83 C4 20                             add     rsp, 20h
.text:0000000180070207 41 5E                                   pop     r14
.text:0000000180070209 5F                                      pop     rdi
.text:000000018007020A 5E                                      pop     rsi
.text:000000018007020B C3                                      retn
.text:000000018007020B                         sub_180070140   endp
.text:000000018007020B
```

# Method

Just put atached files:
    - libcrypto-1_1-x64.dll
    - plasticity_patcher.dll
to D:\Plasticity\app-1.4.10\resources\app\.webpack\renderer directory

plasticity_patcher.dll is just inmemory patcher that will do all job for You!