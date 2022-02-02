BITS 64

    global asm_putc

    section .text

asm_putc:

    push rbp                        ; prologue
    mov rbp, rsp

    push rsi
    push rdx
    push rdi

    mov rax, 1                  ; write syscall
    mov rsi, rsp                ; Character
    mov rdi, 1                  ; stdout
    mov rdx, 1                  ; one byte
    syscall

end:

    pop rdi
    pop rdx
    pop rsi

    mov rsp, rbp                    ; epilogue
    pop rbp

    ret
