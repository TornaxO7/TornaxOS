#include <stdint.h>

/* =========================
 * THE MAIN KERNEL FILE
 * ========================= */
void kernel_main()
{
    volatile uint16_t * ptr = (volatile uint16_t *) 0xB8000;
    *ptr = 'x';
}
