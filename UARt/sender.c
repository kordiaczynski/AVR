
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main()
{
	
	PORTD  = 2;
	uart_init();
	
	unsigned int input = 0x1;
	unsigned int output = 0x0;
	
	DDRB   = 0x00;
	DDRB  |=  (1 << output );
	PORTB |=  (1 << input );


		
	while(1)
	{	
		
		if(( PINB & ( 1<< input )) == 0 )
		{

			PORTB |= 1;
			uart_transmit('a');		
		}
		else
		{

			PORTB &= ~1;
			

		}
		
		
		
	}

	return 0;
}
