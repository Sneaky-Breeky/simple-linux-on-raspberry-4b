#ifndef _P_GPIO_H
#define _P_GPIO_H

#include "peripherals/base.h"

#define GPIO_BASE (PBASE + 0x200000)
#define GPFSEL1 (GPIO_BASE + 0x04)
// used to set GPIO pin
#define GPSET0 (GPIO_BASE + 0x1c)
// to clear GPIO pin
#define GPCLR0 (GPIO_BASE + 0x28)
// pull-up/pull-down reg
#define GPIO_PUP_PDN_CNTRL_REG0 (GPIO_BASE + 0xe4)
#endif