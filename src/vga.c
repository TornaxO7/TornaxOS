#ifndef VGA
#define VGA

/* ==============
 * Libraries
 * ============== */
#include <stdint.h>
#include <stddef.h>

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

static const size_t VGA_MAX_WIDTH = 80;
static const size_t VGA_MAX_HEIGHT = 25;

/* ==============
 * Functions
 * ============== */
// for general information:
//  https://en.wikipedia.org/wiki/VGA_text_mode
static inline uint8_t vga_get_color(enum VGA_COLOR fg, enum VGA_COLOR bg)
{
    return fg | bg << 4;
    //return ((blink & 0b1) << 7) | ((bg & 0b111) << 4) | (fg & 0b1111);
}

static inline uint16_t vga_get_char(unsigned char character, uint8_t color)
{
    return (uint16_t) color << 8 | (uint16_t) character;
}

#endif /* VGA */
