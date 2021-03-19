.section .init
.type _init @function
.global _init

_init:
    push  %ebp
    movl  %esp, %ebp
    
    // gcc will enter the content of crtbegin.o here

.section .fini
.type _fini @function
.global _fini

_fini:
    push  %ebp
    movl  %esp, %ebp
    // gcc will put the content of crtbegin.o here
