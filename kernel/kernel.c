// kernel/kernel.c - Basic kernel code with graphics and font rendering

#include "graphics.h"
#include "font.h"

void kernel_main(void) {
    init_graphics();

    // Clear screen by drawing a black rectangle over the entire screen
    draw_rect(0, 0, VGA_WIDTH, VGA_HEIGHT, 0);

    // Draw a string "Hello, S OS!" at position (50, 50)
    draw_string(50, 50, "Hello, S OS!", 15);

    // Infinite loop to keep the kernel running
    while (1) {
        // Halt the CPU to save power between interrupts
        asm volatile ("hlt");
    }
}
