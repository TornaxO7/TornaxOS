#ifndef KLIB
#define KLIB

/* 
 * ---------------------------------------------------------
 * Filename: klib.h
 * Author: TornaxO7
 * Last changes: 22.03.21
 * Version: 1.0 Usage: 
 *     This file includes a libc compared library to use
 *     in the low level section.
 * ---------------------------------------------------------
 */

/* ===============
 * Includings
 * =============== */
#include <stddef.h>
#include <stdint.h>

/*
 * What does it do?
 *	Get the length of the string.
 *	The length will be <= SIZE_MAX.
 *  
 * Parameters:
 *	string: The string where to lookup its length.
 *
 * Return values:
 *	Its length.
 */
size_t kstrlen(const char * string);

#endif /* KLIB */
