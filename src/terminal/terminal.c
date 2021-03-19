#ifndef TERMINAL
#define TERMINAL

#include "terminal.h"

/* ============
 * Globals
 * ============ */
struct Terminal term;

/* ==============
 * Functions
 * ============== */
void _terminal_error_puts(const char * msg)
{
    // print out the '[ERROR] ' sign
    _terminal_setcolor(VGA_COLOR_RED);
    terminal_printf("[ERROR] ");
    _terminal_setcolor(VGA_COLOR_LIGHT_RED);

    // print out the actual message
    terminal_puts(msg);

    _terminal_setcolor(VGA_COLOR_LIGHT_GREY);
}

void __terminal_putchar(char character)
{
    term.buffer [term.row * VGA_WIDTH + term.column] = 
        vga_entry(character, term.color);
}

void __terminal_refresh_state(bool next_line)
{

    /*
     * 1. Did we reached the end of the display-line?
     * 2. Or should we just move on to the next line?
     */
    if (++term.column == VGA_WIDTH || next_line)
    {
        term.column = 0;

        // Did we reach the maximum height?
        if (term.row == VGA_HEIGHT - 1)
        {
            // scroll every line up, to add a new line at the bottom
            __terminal_scroll_down();
        }
        else
            // move on to the next line
            term.row++;
    }
}

void __terminal_scroll_down()
{
    size_t src;   // the line to move up
    size_t dst;   // the destination line where to paste the src

    for (size_t row = 1; row < term.row; row++)
    {
        src = row * VGA_WIDTH;
        dst = src - VGA_WIDTH;

        // Copy the content of the previous line to the current line
        while (term.buffer [src] && src < VGA_WIDTH * (row + 1))
            term.buffer [dst++] = term.buffer [src++];
    }

    // clear the last line
    for (size_t column = term.row * VGA_WIDTH; column < VGA_WIDTH * VGA_HEIGHT; column++)
        term.buffer [column] = ' ';

    term.column = 0;
}

void _terminal_setcolor(uint8_t color)
{
    term.color = color;
}

void terminal_initialize()
{
    term.row    = 0;
    term.column = 0;
    term.color  = vga_entry_color(
        VGA_COLOR_LIGHT_GREY,
        VGA_COLOR_BLACK);

    // The address where to write the stuff
    term.buffer = (uint16_t *) 0xB8000;

    for (size_t row = 0; row < VGA_HEIGHT; row++)
    {
        for (size_t column = 0; column < VGA_WIDTH; column++)
            term.buffer [row * VGA_WIDTH + column] = vga_entry(' ', term.color);
    }
}

void terminal_printf(const char * string)
{
    // TODO: Add some string formatting
    while ((*string))
    {
        terminal_putchar(*string++);
    }
}

void terminal_putchar(char character)
{
    // New line character?
    if (character == '\n')
        term.column = VGA_WIDTH - 1;
    else
        __terminal_putchar(character);

    __terminal_refresh_state(false);
}

void terminal_puts(const char * string)
{
    // Just print the whole string out
    while ((*string))
        terminal_putchar(*string++);

    // add a new line
    __terminal_refresh_state(true);
}

#endif /* TERMINAL */
