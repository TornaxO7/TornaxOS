ENTRY(_start)

SECTIONS
{
    /* Start from 1M, since some BIOS and GRUB stuff are in < 1MB */
    . = 1M;

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
        . = ALIGN(0x10);
        *(COMMON)
        *(.bss)
        PROVIDE(stack_top = .);
        . = . + 8192;
        PROVIDE(stack_bottom = .);
    }
}
