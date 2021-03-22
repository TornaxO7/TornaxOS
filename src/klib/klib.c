/* ===============
 * Includings
 * =============== */
#include "klib.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>

/* ==============
 * Functions
 * ============== */
size_t kstrlen(const char * string)
{
    size_t length = 0;

    while (*string++ && length < SIZE_MAX)
        length++;

    return length;
}
