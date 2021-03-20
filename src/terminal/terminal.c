/* ===============
 * Includings
 * =============== */
#include "terminal.h"

/* ============
 * Globals
 * ============ */
struct Terminal terminal;

/* ==============
 * Functions
 * ============== */
void __terminal_initialize()
{
    terminal.column = 0;
    terminal.row = 0;
    terminal.color = vga_get_color(
        VGA_COLOR_LIGHT_GREY,
        VGA_COLOR_BLACK,
        0
    );
    terminal.buffer = (uint16_t *) 0xB8000;
}

void terminal_putchar(char character)
{
    // put the character to the buffer
    terminal.buffer[terminal.row * VGA_MAX_WIDTH + terminal.column] =
        vga_get_char(character, terminal.color);

    // refresh the state of the terminal
    if (++terminal.column == VGA_MAX_WIDTH || character == '\n')
    {
        terminal.column = 0;

        if (++terminal.row == VGA_MAX_HEIGHT)
        {
            // move the row back to the bottom line
            terminal.row--;

            /*
             *  We need to scroll down
             *  => Move each line one line up
             *  => Clear the bottom line
             */
            uint16_t row;
            uint16_t column;
            for (row=1; row<VGA_MAX_HEIGHT-1; row++)
                for (column=0; column < VGA_MAX_WIDTH; column++)
                    terminal.buffer[(row - 1) * VGA_MAX_HEIGHT + column] = 
                        terminal.buffer[row * VGA_MAX_HEIGHT + column];
        }
    }
}

void terminal_puts(const char * string)
{
    const char * tmp = string;
    while (*tmp)
        terminal_putchar(*tmp++);

    // add the newline character as expected
    terminal_putchar('\n');
}
