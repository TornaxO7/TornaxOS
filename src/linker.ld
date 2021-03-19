/* Bootloader will start at this symbol */
ENTRY(_start)

/*
 * Tell where the various sections of the object files will be put in the final
 * kernel image
 */
SECTIONS
{
    /* Start at 1 MiB */
    . = 1M;

    /* 
     * Put the multiboot header first, to recognize the file-format.
     * Than we're putting the .text section
     */
    .text BLOCK(4K) : ALIGN(4K)
    {
        *(.multiboot)
        *(.text)
    }
    
    /* read only data */
    .rodata BLOCK(4K) : ALIGN(4K)
    {
        *(.data)
    }

    /* read-write data (uninitialized) and the stack */
    .bss BLOCK(4K) : ALIGN(4K)
    {
        *(COMMON)
        *(.bss)
    }
}
