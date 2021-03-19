/* ===============
 * Includings
 * =============== */
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "../vga.c"           // vga_entry_color, vga_entry

/* ============
 * Globals
 * ============ */
struct Terminal {
    size_t     row;
    size_t     column;
    uint8_t    color;
    uint16_t * buffer;
};

/* ==============
 * Functions
 * ============== */
void __terminal_putentryat(char character);
void __terminal_refresh_state(bool next_line);  // Adjust the column and row
void __terminal_scroll_down();
void _terminal_error_puts(const char * msg);
void _terminal_setcolor(uint8_t color);
void terminal_initialize();
void terminal_printf(const char * string);
void terminal_putchar(char character);
void terminal_puts(const char * string);
