#ifndef LIBC
#define LIBC

/* ===============
 * Includings
 * =============== */
#include <limits.h>
#include <stddef.h>

/* ==============
 * Constants
 * ============== */

/* ==============
 * Functions
 * ============== */
size_t strlen(const char * string)
{
    size_t len = 0;

    while (string [len] && len < UINT_MAX)
        len++;

    return len;
}

void strcpy(char * src, char * dst)
{
    while ((*src))
        *dst++ = *src++;
}

#endif /* LIBC */
