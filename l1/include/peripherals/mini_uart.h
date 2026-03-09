#ifndef	_P_MINI_UART_H
#define	_P_MINI_UART_H

#include "peripherals/base.h"

#define AUX_BASE (PBASE + 0x215000)
#define AUX_ENABLES (AUX_BASE + 0x04)
#define AUX_MU_IO_REG (AUX_BASE + 0x40)
#define AUX_MU_IER_REG (AUX_BASE + 0x44)
#define AUX_MU_IIR_REG (AUX_BASE + 0x48)
#define AUX_MU_CNTL_REG (AUX_BASE + 0x60)
#define AUX_MU_LCR_REG (AUX_BASE + 0x4c)
#define AUX_MU_MCR_REG (AUX_BASE + 0x50)
#define AUX_MU_LSR_REG (AUX_BASE + 0x54)
#define AUX_MU_BAUD_REG (AUX_BASE + 0x68)

#endif