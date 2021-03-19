.section .init
    // gcc wiill put the content of crtend.o .init section here
    popl  %ebp
    ret

.section .fini
    // gcc will put the content of crtend.o's .fini section here
    popl  %ebp
    ret
