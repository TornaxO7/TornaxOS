ENTRY(_start);

SECTIONS 
{
    /*
     * https://www.gnu.org/software/grub/manual/multiboot/multiboot.html#OS-image-format
     *  1. Header must be withing the first 8192 bytes of the OS image
     *  2. Must be longword (32-bit) aligned
     */
    .text :
    {
        *(.multiboot_header)
        *(.text)
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(.bss)
        *(COMMON)
    }

}
