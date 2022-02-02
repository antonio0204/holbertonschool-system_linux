BITS 64
	global asm_memcpy	; export 'asm_memcpy' function

	section .text

asm_memcpy:
        xor     ecx, ecx
        test    rdx, rdx
        mov     rax, rdi
        jz      ?_002   

?_001:  movzx   r8d, byte [rsi+rcx]
        mov     byte [rax+rcx], r8b
        add     rcx, 1  
        cmp     rcx, rdx
        jnz     ?_001   
?_002:
        ret
