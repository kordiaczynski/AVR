
#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"

int main()
{
	uart_init();
	unsigned int input = 0x1;
	unsigned int output = 0x2;                      //I had to change that because I've broken one pin
	
	DDRB   = 0x00;                                  //All pins as input
	DDRB  |=  (1 << output );			//Set pin PB0 as output -1
	PORTB |=  (1 << input );			//Connet pin PB1 ( input because of 0 ) to pull up resistor

	_delay_ms(1000); 				//Every time when I put the power on sender it 		
	while(1)					//think that button is pressed so I wait for a monent
	{	
		
		if(( PINB & ( 1<< input )) == 0 )       //Zero means neutral cabel connected
		{
			PORTB &= ~_BV(output);                    //Zero means connect neutral to this out
			uart_transmit('a');		
		}
		else
		{
			PORTB |= _BV(output);			
		}
		
		
		
	}

	return 0;
}
