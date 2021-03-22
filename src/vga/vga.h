#ifndef VGA
#define VGA
/* ===============
 * Includings
 * =============== */
#include <stdint.h>

/* ============
 * Globals
 * ============ */
enum VGA_COLOR {
    VGA_COLOR_BLACK,
    VGA_COLOR_BLUE,
    VGA_COLOR_GREEN,
    VGA_COLOR_CYAN,
    VGA_COLOR_RED,
    VGA_COLOR_MAGENTA,
    VGA_COLOR_BROWN,
    VGA_COLOR_LIGHT_GRAY,
    VGA_COLOR_DARK_GRAY,
    VGA_COLOR_LIGHT_BLUE,
    VGA_COLOR_LIGHT_GREEN,
    VGA_COLOR_LIGHT_CYAN,
    VGA_COLOR_LIGHT_RED,
    VGA_COLOR_LIGHT_MAGENTA,
    VGA_COLOR_YELLOW,
    VGA_COLOR_WHITE,
};

const uint16_t VGA_MAX_WIDTH  = 80;
const uint16_t VGA_MAX_HEIGHT = 25;

/* ==============
 * Functions
 * ============== */
/*
 * What does it do?
 *	It will return the byte value for the appropriate text design.
 *  
 * Parameters:
 *	fg: The foreground color
 *	bg: The background color
 *	blinking: If it should blink or not
 *
 * Return values:
 *	The appropriate byte value for the text.
 */
uint8_t vga_color_get_color(enum VGA_COLOR fg,
                            enum VGA_COLOR bg,
                            int8_t         blinking);

/*
 * What does it do?
 *	Combine the color with the character to get the wordbyte value which
 *	should be displayed.
 *  
 * Parameters:
 *	character: The character to be shown.
 *	color: The colors which the character should have.
 *
 * Return values:
 *	 The wordbyte value of the character.
 */
int16_t vga_get_char(char character, uint8_t color);

#endif /* VGA */
