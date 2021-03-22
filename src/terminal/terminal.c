/* ===============
 * Includings
 * =============== */
#include "terminal.h"
#include <stdarg.h>

/* ============
 * Globals
 * ============ */
struct Terminal terminal;

/* ==============
 * Functions
 * ============== */
void __terminal_initialize()
{
    // set the default values
    terminal.row    = 0;
    terminal.column = 0;
    terminal.color  = vga_color_get_color(VGA_COLOR_LIGHT_GRAY,
                                         VGA_COLOR_BLACK,
                                         0);
    terminal.buffer = (volatile uint16_t *) 0xB8000;

    // clear the screen
    for (uint16_t row = 0; row < VGA_MAX_HEIGHT; row++)
    {
        for (uint16_t column = 0; column < VGA_MAX_WIDTH; column++)
        {
            terminal.buffer [row * VGA_MAX_WIDTH + column] =
                vga_get_char(' ', terminal.color);
        }
    }
}

void terminal_putc(char character)
{

    if (character != '\n')
    {
        // put the character into the screen.
        terminal.buffer [terminal.row * VGA_MAX_WIDTH + terminal.column] =
            vga_get_char(character, terminal.color);
    }

    // refresh the terminal state
    if (++terminal.column >= VGA_MAX_WIDTH || character == '\n')
    {
        terminal.column = 0;

        if (++terminal.row >= VGA_MAX_HEIGHT)
        {
            // Make sure that the row variable doesn't exceed the buffer
            terminal.row--;

            // we need to scroll down one line!
            // Move each line one up
            for (uint16_t row = 1; row < VGA_MAX_HEIGHT; row++)
            {
                for (uint16_t column = 0; column < VGA_MAX_WIDTH; column++)
                {
                    terminal.buffer [(row - 1) * VGA_MAX_WIDTH + column] =
                        terminal.buffer [row * VGA_MAX_WIDTH + column];
                }
            }
        }
    }
}

void terminal_puts(const char * string)
{
    while (*string)
        terminal_putc(*string++);
    terminal_putc('\n');
}

void terminal_printf(const char * string, ...)
{

    // the previous char which was read
    // it's mainly used, to check, if a '%' was typed
    char   prev = '\0';
    char * tmp;

    va_list varg_ptr;
    va_start(varg_ptr, string);

    while (*string)
    {

        if (prev == '%')
        {
            switch (*string)
            {
                case 'd':
                    break;

                case 's':
                    tmp = va_arg(varg_ptr, char *);
                    while (*tmp)
                        terminal_putc(*tmp++);
                    break;

                default:
                    terminal_putc('%');
                    break;
            }
        }

        else if ((*string) == '%')
            prev = *string;

        else
        {
            terminal_putc(*string);
            prev = '\0';
        }

        // move on to the next character
        string++;
    }

    va_end(varg_ptr);
}

void _terminal_error(const char * error_msg)
{
    // set the error message to red
    terminal.color = vga_color_get_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK, 1);
    terminal_printf("[ERROR] ");

    // turn the error message back to default color
    terminal.color = vga_color_get_color(VGA_COLOR_LIGHT_RED, VGA_COLOR_BLACK, 0);
    terminal_puts(error_msg);

    // reset the color to default
    terminal.color = vga_color_get_color(VGA_COLOR_LIGHT_GRAY, VGA_COLOR_BLACK, 0);
}
