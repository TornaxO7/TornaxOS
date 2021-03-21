.section .text

    .set ALIGN, 1 << 0
    .set MEMINFO, 1 << 1
    .set MAGIC,     0x1BADB002
    .set FLAGS,     ALIGN | MEMINFO
    .set CHECKSUM,  -(MAGIC + FLAGS)

    .section .multiboot_header:
        .align 4
        .long MAGIC   
        .long FLAGS
        .long CHECKSUM

    .global _start
    .type _start @function
    _start:

        // Initialize the stack
        mov $stack_top,  %esp
        call kernel_main
        cli
    1:  hlt
        jmp 1

.section .data
    
.section .bss
    .align 16
    stack_bottom:
        .skip 8192
    stack_top:
