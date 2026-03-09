#include "mini_uart.h"

void kernel_main() 
{
    uart_init();
    uart_send_string("Hello, world!\n");

    while (1)
    {
        char c = uart_recv();

        if (c == '\r') {
            uart_send('\r');
            uart_send('\n');
        } else if (c == 0x7F || c == 0x08) {
            uart_send('\b');
            uart_send(' ');
            uart_send('\b');
        } else {
            uart_send(c);
        }
    }
}