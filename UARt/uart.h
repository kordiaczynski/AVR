
#ifndef UART_H
#define UART_H

#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)

#include <util/setbaud.h>

void uart_init(void);
void uart_transmit(unsigned char data);
unsigned char  uart_receive(void);
#endif
