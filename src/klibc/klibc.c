/* ===============
 * Includings
 * =============== */
#include "klibc.h"

/* ==============
 * Functions
 * ============== */
void kstrcpy(char * dst, char * src)
{
    while (*src)
        *dst++ = *src++;
}
