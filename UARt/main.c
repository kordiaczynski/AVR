#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include <avr/interrupt.h> 






ISR(USART_RXC_vect, ISR_BLOCK )
{
 unsigned char received = UDR;
 if( received == 'a' )
 {
 	PORTB ^= _BV(PB0);
 }


}





int main()
{
	DDRB = 3; // ( 1 << PB0 ) | (1 << PB1);
	PORTB = 1;	
	uart_init();
	UCSRB |= (1 << RXCIE);
	sei();
	while(1)
	{
	}
	return 0;
}
