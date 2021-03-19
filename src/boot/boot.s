/* Multiboot header constants */
.set  ALIGN,    1                 // Align loaded modules on page boundaries
.set  MEMINFO,  2                 // provide memory map
.set  FLAGS,    ALIGN | MEMINFO   // THIS is the multiboot 'flag' field
.set  MAGIC,    0x1BADB002
.set  CHECKSUM, -(MAGIC + FLAGS)  // Checksum of above, to prove we are multiboot

// bit folge of the multiboot standard
.section  .for_bootloader
.align  4
.long MAGIC
.long MAGIC, FLAGS, CHECKSUM

.section .bss
    .align 16
    
    stack_bottom:   // startpoint of the stack
        .skip 16384 //  Allocate 16 KiB for the stack
    
    stack_top:

.section .text
.type _start @function
.global _start  // global makes a symbol visible to ld

_start:
    /*
       The bootloader finished everything:
        - loaded us to protected mode
        - interrupts are disabled
        - processor state is defined as in the multiboot standard
        - Kernel has full control of the CPU
    */

    // setup the stack
    mov   $stack_top, %esp

    call kernel_main
    
    cli         // disable interrupts

stop:  
    hlt      // lock the computer
    jmp stop    // jump back to halt
