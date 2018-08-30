#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <util/setbaud.h>




void init_registers ( void ) {
	UCSRC &= ~_BV(URSEL);
        DDRB  = 0xff;
	PORTB = 0xff;	
}

void init_uart ( void ) {
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	UCSRB |= _BV( RXEN ) | _BV( TXEN ) | _BV( RXCIE ) | _BV( TXCIE ); 
	UCSRC |= _BV( URSEL ) | _BV( UCSZ1 ) | _BV( UCSZ0 );
	sei();
}

void transmit( unsigned char data )
{
	while( ( UCSRA & _BV( UDRE ) ) == 0 ) {};
	UDR = data;
}


ISR( USART_RXC_vect, ISR_BLOCK )
{
	unsigned char data = UDR;	
	PORTB ^= _BV(PB1);		
}

ISR( USART_TXC_vect, ISR_BLOCK)
{
	
}




int main(void)
{	
	init_registers();
	init_uart();


	while(1)
	{
		_delay_ms(500);
		transmit('a');

	}


	return 0;
}
