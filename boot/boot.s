; boot/boot.s - Assembly code for the bootloader

section .text
    global _start

_start:
    ; Load the kernel
    mov eax, kernel
    jmp eax

section .data
kernel:
    incbin "kernel/kernel.bin"
