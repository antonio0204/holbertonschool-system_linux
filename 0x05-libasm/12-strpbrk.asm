
BITS 64

	;; declare prerequistes
	global asm_strpbrk 	; EXPORT our 'asm_strcspn' function

	section .text
	
asm_strpbrk:; Function begin
        movzx   r8d, byte [rdi]                         ; 0000 _ 44: 0F B6. 07
        mov     rax, rdi                                ; 0004 _ 48: 89. F8
        test    r8b, r8b                                ; 0007 _ 45: 84. C0
        jz      ?_005                                   ; 000A _ 74, 34
        movzx   edi, byte [rsi]                         ; 000C _ 0F B6. 3E
?_001:  test    dil, dil                                ; 000F _ 40: 84. FF
        jz      ?_004                                   ; 0012 _ 74, 1C
        cmp     dil, r8b                                ; 0014 _ 44: 38. C7
        jz      ?_005                                   ; 0017 _ 74, 27
        lea     rdx, [rsi+1H]                           ; 0019 _ 48: 8D. 56, 01
        jmp     ?_003                                   ; 001D _ EB, 0A

; Filling space: 1H
; Filler type: NOP
;       db 90H

ALIGN   8
?_002:  add     rdx, 1                                  ; 0020 _ 48: 83. C2, 01
        cmp     r8b, cl                                 ; 0024 _ 41: 38. C8
        jz      ?_005                                   ; 0027 _ 74, 17
?_003:  movzx   ecx, byte [rdx]                         ; 0029 _ 0F B6. 0A
        test    cl, cl                                  ; 002C _ 84. C9
        jnz     ?_002                                   ; 002E _ 75, F0
?_004:  add     rax, 1                                  ; 0030 _ 48: 83. C0, 01
        movzx   r8d, byte [rax]                         ; 0034 _ 44: 0F B6. 00
        test    r8b, r8b                                ; 0038 _ 45: 84. C0
        jnz     ?_001                                   ; 003B _ 75, D2
; Filling space: 3H
; Filler type: Multi-byte NOP
;       db 0FH, 1FH, 00H

ALIGN   8
?_005:
; Note: Prefix bit or byte has no meaning in this context
        ret                                             ; 0040 _ F3: C3
; _strpbrk End of function
