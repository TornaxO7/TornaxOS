/* ===============
 * Includings
 * =============== */
#include "terminal/terminal.c"

/* =========================
 * Main kernel function
 * ========================= */
void kernel_main()
{
    __terminal_initialize();
    terminal_puts("Hello kernel!");
}
