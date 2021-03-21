.section .text

    .set MAGIC,     0x1BADB002
    .set FLAGS,     0b00
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
        cli
        call kernel_main

loop: hlt
        jmp loop

.section .data
    
.section .bss
    .align 16
    stack_bottom:
        .skip 8192
    stack_top:
