BITS 64
	global asm_strchr	; export 'asm_strchr' function

	section .text

asm_strchr:
        mov     rax, rdi
        jmp     ?_002   

?_001:  add     rax, 1  
        test    dl, dl  
        jz      ?_003   
?_002:  movzx   edx, byte [rax]                         
        cmp     dl, sil 
        jnz     ?_001   

        ret             

?_003:  xor     eax, eax
        ret             
