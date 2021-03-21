#ifndef TERMINAL
#define TERMINAL

/* ==============
 * Libraries
 * ============== */
#include "../vga.c"
#include <stddef.h>

/* ============
 * Structs
 * ============ */
struct Terminal {
    size_t     column;  // at which column we're currently
    size_t     row;     // at which row we're currently
    uint8_t    color;   // The color code (foreground and background)
    uint16_t * buffer;  // The VGA buffer
};

/* ==============
 * Functions
 * ============== */
void __terminal_initialize();
void terminal_putchar(char character);
void terminal_puts(const char * string);

#endif /* TERMINAL */
