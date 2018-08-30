#include "uart.h"
#include <avr/io.h>
void uart_init(void)
{
	UBRRH = (BAUDRATE>>8);
	UBRRL = BAUDRATE;

	UCSRB = (1 << RXEN ) | ( 1 << TXEN ); 
	UCSRC = (1 << URSEL ) | (1 << UCSZ0 ) || (1 <<UCSZ1 );
}

void uart_transmit(unsigned char data)
{
	while(!(UCSRA) & (1<<UDRE ));
	UDR = data;
}

unsigned char  uart_receive(void)
{
	while(!(UCSRA) & (1<<RXC ));
	return UDR;
}


