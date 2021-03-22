/* ===============
 * Inlcudings
 * =============== */
#include "libc.h"

/* ==============
 * Functions
 * ============== */
uint16_t strtohu(char * ptr, char ** ptr2, uint8_t base)
{
    uint16_t ret   = 0;
    uint16_t power = 1;
    uint16_t index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 4 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 5 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}

uint32_t strtolu(char * ptr, char ** ptr2, uint8_t base)
{
    uint32_t ret   = 0;
    uint32_t power = 1;
    uint8_t  index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 9 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 10 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}

uint64_t strtohllu(char * ptr, char ** ptr2, uint8_t base)
{
    uint64_t ret   = 0;
    uint64_t power = 1;
    uint8_t  index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 19 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 20 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}

int16_t strtohi(char * ptr, char ** ptr2, uint8_t base)
{
    int16_t  ret   = 0;
    int16_t  power = 1;
    uint16_t index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 4 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 5 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}

int32_t strtold(char * ptr, char ** ptr2, uint8_t base)
{
    uint32_t ret   = 0;
    uint32_t power = 1;
    uint8_t  index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 9 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 10 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}

int64_t strtolld(char * ptr, char ** ptr2, uint8_t base)
{
    uint64_t ret   = 0;
    uint64_t power = 1;
    uint8_t  index;

    *ptr2 = ptr;
    index = 0;

    /*
     * Multiplier will represent 'x'.
     * Input: '12345'
     *
     *  1*x^5 + 2*x^4 + 3*x^3 + 4*x^2 + 5*x^1
     */
    while (index++ < 19 && *(++ptr2))
        power *= base;

    *ptr2 = ptr;
    index = 0;

    while (index++ < 20 && *ptr2)
    {
        ret += ((**ptr2) - 0x30) * power;

        // decrement the power of the base
        power /= base;

        // point to the next integer in the string
        (*ptr2)++;
    }

    return ret;
}
