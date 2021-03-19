/* =================
 * preparations
 * ================= */
// make sure that we're targeting the correct system
#ifdef __linux__
#error "you're using a compiler which targets the wrong architecture!"
#endif /* __linux__ */

// make sure that the compiler targets the correct system
#ifndef __i386__
#error "you need a compiler which targets an ix86-elf system"
#endif /* __i386__ */

/* ===============
 * includings
 * =============== */

// my ones
#include "terminal/terminal.c"

/* ================
 * actual code
 * ================ */
void kernel_main()
{
    // initialize the terminal interface
    terminal_initialize();

    terminal_puts("test");
    _terminal_error_msg("kernel panic");
    terminal_puts("i use arch btw");
}
