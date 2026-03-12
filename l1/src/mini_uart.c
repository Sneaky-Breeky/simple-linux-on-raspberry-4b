#include "utils.h"
#include "peripherals/mini_uart.h"
#include "peripherals/gpio.h"

#define SYS_CLOCK 5000000
#define BAUD_RATE 115200

void uart_send(char c) {
    while (1) {
        if (get32(AUX_MU_LSR_REG) & 0x20) {
            break;
        }
    }
    put32(AUX_MU_IO_REG, c);
}

char uart_recv(void) {
    while (!(get32(AUX_MU_LSR_REG) & 0x01));
    
    return (get32(AUX_MU_IO_REG) & 0xFF);
}

void uart_send_string(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            uart_send('\r');
        uart_send(str[i]);
    }
}

void uart_init()
{
    unsigned int selector;
    unsigned int reg;

    selector = get32(GPFSEL1);
    // reset bits 12-14 of GPFSEL1 (FSEL14) to 0x0
    selector &= ~(7 << 12);
    // set function ALT 5, TXD1
    selector |= 2 << 12;
    // reset bits 15-17 of GPFSEL1 (FSEL15) to 0x0
    selector &= ~(7 << 15);
    // set function ALT 5, RXD1
    selector |= 2 << 15;
    // write back
    put32(GPFSEL1, selector);

    reg = get32(GPIO_PUP_PDN_CNTRL_REG0);
    // GPIO 14/15, no pull
    reg &= ~((3 << 30) | (3 << 28));
    put32(GPIO_PUP_PDN_CNTRL_REG0, reg);

    // enable mini-uart
    put32(AUX_ENABLES, 1);
    // disable interrupts
    put32(AUX_MU_IER_REG, 0);
    // disable auto flow control and RTS/CTS
    put32(AUX_MU_CNTL_REG, 0);
    // reset fifo, clear interrupts
    put32(AUX_MU_IIR_REG, 0xc6);
    // set 8bit mode
    put32(AUX_MU_LCR_REG, 3);
    // disable RTS line, althought it doesn't exist on pi4b
    put32(AUX_MU_MCR_REG, 0);
    // set baud rate
    unsigned int baud_rate = (SYS_CLOCK / (8 * BAUD_RATE)) - 1;
    put32(AUX_MU_BAUD_REG, baud_rate);

    // enable transmitter and receiver
    put32(AUX_MU_CNTL_REG, 3);
}