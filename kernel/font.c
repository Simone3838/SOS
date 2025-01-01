// kernel/font.c - Font rendering functions

#include "font.h"
#include "graphics.h"

void draw_char(int x, int y, char c, uint8_t color) {
    // Ensure the character is within the supported range
    if (c < 0 || c >= 128) return;

    // Get the bitmap for the character
    const uint8_t *bitmap = font_data[(int)c];

    for (int i = 0; i < FONT_HEIGHT; ++i) {
        for (int j = 0; j < FONT_WIDTH; ++j) {
            if (bitmap[i] & (1 << (7 - j))) {
                put_pixel(x + j, y + i, color);
            }
        }
    }
}

void draw_string(int x, int y, const char *str, uint8_t color) {
    while (*str) {
        draw_char(x, y, *str++, color);
        x += FONT_WIDTH;
    }
}
