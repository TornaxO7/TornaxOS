#ifndef LIBC
#define LIBC

/* 
 * ---------------------------------------------------------
 * Filename: libc.h
 * Author: TornaxO7
 * Last changes: 22.03.21
 * Version: 1.0
 * Usage: 
 *     Here is a little reimplemenation of the standard
 *     C library, just worse.
 * ---------------------------------------------------------
 */
/* ===============
 * Includings
 * =============== */
#include <stddef.h>
#include <stdint.h>

/* ==============
 * Functions
 * ============== */
/*
 * What does it do?
 *	These functions convert a string to their given number.
 *	The ending after "strto" repesents their return type.
 *  
 * Parameters:
 *	ptr: The string to convert to a number.
 *	ptr2: Points in the string *after* the number like skipping the number.
 *	base: The base of your number.
 */
uint16_t strtohu(char * ptr, char ** ptr2, uint8_t base);
uint32_t strtolu(char * ptr, char ** ptr2, uint8_t base);
uint64_t strtollu(char * ptr, char ** ptr2, uint8_t base);

int16_t strtohi(char * ptr, char ** ptr2, uint8_t base);
int32_t strtol(char * ptr, char ** ptr2, uint8_t base);
int64_t strtoll(char * ptr, char ** ptr2, uint8_t base);

#endif /* LIBC */
