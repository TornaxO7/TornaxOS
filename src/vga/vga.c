/* ===============
 * Includings
 * =============== */
#include "vga.h"

/* ==============
 * Functions
 * ============== */
uint8_t vga_color_get_color(enum VGA_COLOR fg,
                            enum VGA_COLOR bg,
                            int8_t         blinking)
{
    return ((blinking & 0x1) << 8) | ((bg & 0x7) << 4) | (fg & 0xf);
}

int16_t vga_get_char(char character, uint8_t color)
{
    return (color << 8) | character;
}
