BITS 64
	global asm_strcmp

	section .text

asm_strcmp:
        movsx   edx, byte [rdi]
        test    dl, dl
        jz      ?_003
        movsx   ecx, byte [rsi]
        xor     eax, eax
        cmp     dl, cl
        jz      ?_002
        jmp     ?_004

?_001:  add     rax, 1
        movsx   ecx, byte [rsi+rax]
        cmp     dl, cl
        jnz     ?_004
?_002:  movsx   edx, byte [rdi+rax+1H]
        test    dl, dl
        jnz     ?_001
?_003:  xor     eax, eax
        ret

?_004:  sub     edx, ecx
        xor     eax, eax
        test    edx, edx
        setg    al
        lea     eax, [rax+rax-1H]
        ret

