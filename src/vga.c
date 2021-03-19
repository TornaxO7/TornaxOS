#ifndef VGA
#define VGA

/* ===============
 * Includings
 * =============== */
#include <stddef.h>
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

static const size_t VGA_WIDTH  = 80;
static const size_t VGA_HEIGHT = 5;

/* ===================================
 * Impelmentation of the functions
 * =================================== */
static inline uint8_t
vga_entry_color(enum VGA_COLOR fg,
                enum VGA_COLOR bg)
{
    return fg | bg << 4;
}

// this returns the given given binary code to be able to print the character
// with the given character
static inline uint16_t vga_entry(unsigned char uc,
                                 uint8_t       color)
{
    return (uint16_t) uc | (uint16_t) color << 8;
}


#endif /* VGA */
