/* ===============
 * Includings
 * =============== */
#include "terminal/terminal.c"
#include "terminal/terminal.h"

/* =========================
 * THE MAIN KERNEL FILE
 * ========================= */
void kernel_main()
{

    char buffer[] = "Buffer test";

    __terminal_initialize();
    terminal_printf("%s", buffer);
}
