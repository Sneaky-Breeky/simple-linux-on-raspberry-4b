#include "mm.h"

.section ".text.boot"

// only start one core
.globl _start
_start:
    // get processor id from MPIDR_EL1 reg
    mrs x0, mpidr_el1
    // only use the lowest 8 bits
    and x0, x0, #0xff
    // if proc id is not 0, hang, otherwise jump to master
    cbz x0, master
    b   proc_hang

proc_hang:
    // low power wait for event
    wfe
    b proc_hang

master:
    adr x0, bss_begin
    adr x1, bss_end
    sub x1, x1, x0
    // zero out the bss section
    bl  memzero

    // #LOW_MEMORY = 4Mb, sufficiently large for kernel
    mov sp, #LOW_MEMORY
    // load kernel at address 0
    bl kernel_main