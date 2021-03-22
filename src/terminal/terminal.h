#ifndef TERMINAL
#define TERMINAL
/* ===============
 * Includings
 * =============== */
#include "../vga/vga.c"
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>

/* =================
 * Section name
 * ================= */
struct Terminal {
    uint16_t   row;
    uint16_t   column;
    uint8_t    color;
    volatile uint16_t * buffer;
};

/* ==============
 * Functions
 * ============== */
/*
 * What does it do?
 *	Initialize the terminal representer and clear the current screen
 *	by replacing each character with whitespaces.
 */
void __terminal_initialize();

/*
 * What does it do?
 *	Print one char out.
 *	It will also adjust the values of the terminal struct, like remembering
 *	to increment to the next column and checking if it should move on to the
 *	next line.
 *
 *	NOTE: '\n' can be inserted here to add a new line.
 *  
 * Parameters:
 *	character: The character to print out.
 */
void terminal_putc(char character);

/*
 * What does it do?
 *	Print the given string onto the screen.
 *	This function also automatically adds a '\n' in the end.
 *  
 * Parameters:
 *	 string: The given string to print out.
 */
void terminal_puts(const char * string);

/*
 * What does it do?
 *	This will behave like the printf from the libc.
 *	Currently it can only format the following chars:
 *	  %d
 *  
 * Parameters:
 *	string: The string to print out.
 *	amount_args: How many arguments *at least* you provide.
 *	    This should avoid printf exploits, *if you're doing it correctly*
 */
void terminal_printf(const char * string, ...);

/*
 * What does it do?
 *	This will print a beatiful made error message, formatted as follows:
 *	  
 *	  [ERROR] <string>\n
 *  
 * Parameters:
 *	error_msg: The error message to be printed out.
 */
void _terminal_error(const char * error_msg);

#endif /* TERMINAL */
