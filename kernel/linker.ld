/* kernel/linker.ld - Linker script for the kernel */
ENTRY(kernel_main)

SECTIONS
{
    . = 0x100000;

    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss) }
}
