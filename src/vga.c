#ifndef VGA
#define VGA

/* ==============
 * Libraries
 * ============== */
#include <stdint.h>

/* ==============
 * Constants
 * ============== */
enum VGA_COLOR {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GREY,
    VGA_COLOR_DARK_GREY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_LIGHT_BROWN,
    VGA_COLOR_WHITE,
};

static const uint16_t VGA_MAX_WIDTH = 80;
static const uint16_t VGA_MAX_HEIGHT = 40;

/* ==============
 * Functions
 * ============== */
// for general information:
//  https://en.wikipedia.org/wiki/VGA_text_mode
int8_t vga_get_color(int8_t fg, int8_t bg, int8_t blink)
{
    return ((blink & 0b1) << 7) | ((bg & 0b111) << 4) | (fg & 0b1111);
}

uint16_t vga_get_char(char character, int8_t color)
{
    return (uint16_t) color << 8 | (uint16_t) character;
}

#endif /* VGA */
