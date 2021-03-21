/* ======================
 * Magic boot header
 * ====================== */
.set  MAGICBOOT, 0x1BADB002
.set  FLAGS,     0x10
.set  CHECKSUM,  -(MAGICBOOT + FLAGS)

.section .text
    .section .multiboot
        .align 4
        .long MAGICBOOT
        .long FLAGS
        .long CHECKSUM

/* ==========
 * Stack
 * ========== */
.section .bss
    .section .stack
        stack_top:
            .skip 8192
        stack_bottom:

/* =================
 * Main starter
 * ================= */
.global _start
.type _start, @function
_start:
    // setup the stack
    mov stack_bottom, %esp
    call kernel_main
