#include <stdint.h>

/* =========================
 * THE MAIN KERNEL FILE
 * ========================= */
void kernel_main()
{
    uint16_t * ptr = (uint16_t *) 0xB8000;
    *ptr = 'x';
}
