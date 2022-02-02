BITS 64
	global asm_strstr	; export 'asm_strstr' function

	section .text

asm_strstr:
        movzx   edx, byte [rsi]
        mov     rax, rdi
        test    dl, dl
        jz      ?_005
        movzx   ecx, byte [rdi]
        test    cl, cl
        jz      ?_003
        cmp     dl, cl
        jnz     ?_002
        jmp     ?_006

?_001:  cmp     dl, al
        jz      ?_004
?_002:  add     rdi, 1
        movzx   eax, byte [rdi]
        test    al, al
        jnz     ?_001
?_003:  xor     eax, eax
        ret                    
?_004:  mov     rax, rdi
?_005:
        ret
?_006:
        ret
