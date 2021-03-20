#ifndef TERMINAL
#define TERMINAL

/* ==============
 * Libraries
 * ============== */
#include "../vga.c"

/* ============
 * Structs
 * ============ */
struct Terminal {
    uint16_t column;
    uint16_t row;
    int8_t color;
    uint16_t * buffer;
};

/* ==============
 * Functions
 * ============== */
void __terminal_initialize();
void terminal_putchar(char character);
void terminal_puts(const char * string);

#endif /* TERMINAL */
