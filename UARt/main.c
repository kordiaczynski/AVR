#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
#include <avr/interrupt.h> 






ISR(USART_RXC_vect, ISR_BLOCK )
{
 //while ( ! (UCSRA & ( 1 << RXC )) == 0 ) {};
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
	PORTD = 2;
	uart_init();
	UCSRB |= (1 << RXCIE);
	sei();
	while(1)
	{
/*		unsigned char received = uart_receive();
		if( received == 'a' )
		{


			PORTB &= ~_BV(PB0);
			_delay_ms(300);
		}
		else
		{

			PORTB |= _BV(PB0);

		}
*/
	}
	return 0;
}
