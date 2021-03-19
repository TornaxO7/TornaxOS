/* =================
 * Preparations
 * ================= */
// Make sure that we're targeting the correct system
#ifdef __linux__
#error "You're using a compiler which targets the wrong architecture!"
#endif /* __linux__ */

// Make sure that the compiler targets the correct system
#ifndef __i386__
#error "You need a compiler which targets an ix86-elf system"
#endif /* __i386__ */

/* ===============
 * Includings
 * =============== */

// my ones
#include "terminal/terminal.c"

/* ================
 * Actual code
 * ================ */
void kernel_main()
{
    // initialize the terminal interface
    terminal_initialize();

    terminal_puts("Test");
    _terminal_error_msg("KERNEL PANIC");
    terminal_puts("I use arch btw");
}
