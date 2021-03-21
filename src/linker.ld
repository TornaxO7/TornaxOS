ENTRY(_start)
SECTIONS
{
    /* The mutliboot header */
    .multiboot :
    {
        *(.multiboot)
    }

    .text :
    {
        *(.text)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(.bss)
    }
}
