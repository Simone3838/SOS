// kernel/graphics.h - Basic graphics functions

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <stdint.h>

#define VGA_WIDTH 320
#define VGA_HEIGHT 200

void init_graphics(void);
void put_pixel(int x, int y, uint8_t color);
void draw_rect(int x, int y, int width, int height, uint8_t color);

#endif
