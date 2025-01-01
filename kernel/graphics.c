// kernel/graphics.c - Basic graphics functions implementation

#include "graphics.h"

static uint8_t *vga_buffer = (uint8_t*)0xA0000; // VGA graphics mode memory

void init_graphics(void) {
    // Set VGA mode 13h (320x200, 256 colors)
    asm volatile (
        "mov $0x0013, %ax\n"
        "int $0x10"
    );
}

void put_pixel(int x, int y, uint8_t color) {
    if (x >= 0 && x < VGA_WIDTH && y >= 0 && y < VGA_HEIGHT) {
        vga_buffer[y * VGA_WIDTH + x] = color;
    }
}

void draw_rect(int x, int y, int width, int height, uint8_t color) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            put_pixel(x + j, y + i, color);
        }
    }
}
