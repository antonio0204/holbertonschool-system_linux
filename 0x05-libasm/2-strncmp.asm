BITS 64
	global asm_strncmp	; export 'asm_strncmp' function

	section .text

asm_strncmp:


loop:
	cmp rdx, 0
	je equal
	mov r8b,	[rdi]
	mov r9b,	[rsi]
	cmp r8b,	r9b
	jl less
	jg greater
	cmp r8b,	0
	je equal
	inc rdi
	inc rsi
	dec rdx
	jmp loop

less:
	mov eax, -1
	ret

greater:
	mov eax, 1
	ret

equal:
	mov eax, 0
    ret
