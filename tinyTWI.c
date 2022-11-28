/*
 * tinyTWI.c
 *
 * Created: 19/11/2022 15:27:15
 *  Author: youssef
 */ 

#include "tinyTWI.h"
#define TIMEOUT 1000
uint16_t t_count = 0;

void i2c_init()
{
	USIDR = 0xFF;
	USICR = (1<<USIWM1)|(1<<USICS1)|(1<<USICLK);		//TWI mode
	DDRB |= (1<<PB0)|(1<<PB2);							//SDA & SCL direction as output
	PORTB |= (1<<PB0)|(1<<PB2);							//SDA & SCL default state
}

uint8_t i2c_ack()
{
	uint8_t ack_bit = 0;
	DDRB&=~(1<<PB0);									//Change direction of SDA to receive acknowledge bit
	USISR|=(1<<USICNT3)|(1<<USICNT2)|(1<<USICNT1);		//Set counter to 1110 to force it to overflow when ACK bit is received
	USICR|=(1<<USITC);		
					//Clock signal from SCL
	while((PINB&(1<<PB2)));
	_delay_us(3);
	if(~PINB & 1){
		ack_bit = 1;
		} else {
		ack_bit = 0;
	}
	_delay_us(2);
	USICR|=(1<<USITC);
	while(!(USISR&(1<<USIOIF)));					//Wait for counter to overflow when ack bit is received
	_delay_us(5);
	USISR|=(1<<USIOIF);									//Clear counter overflow flag
	DDRB |= (1<<PB0);									//Change direction of SDA back to output
	
	return ack_bit;
}

void i2c_transfer()
{
	if(USIDR & (1<<7)){
		PORTB|=(1<<PB0);
	}
	do
	{
		USICR|=(1<<USITC);								//Clock signal from SCL
		while((PINB&(1<<PB2)));						//Waiting for SCL to go high
		_delay_us(5);
		USICR|=(1<<USITC);
		if(USIDR & (1<<7)){
			PORTB|=(1<<PB0);
		}							//Toggle SCL to go low
		_delay_us(5);
	}while(!(USISR&(1<<USIOIF)));						//Repeat clock generation at SCL until the counter overflows and a byte is transferred
	_delay_us(5);
	PORTB&=~(1<<PB0);
	USISR|=(1<<USIOIF);									//Clear overflow flag
}

void i2c_start()
{
	cli();
	DDRB |= (1<<PB0)|(1<<PB2);	
	PORTB&=~(1<<PB0);									//Pulling SDA line low
	_delay_us(5);
	PORTB&=~(1<<PB2);									//Pulling SCL line low
	_delay_us(5);
	while(!(USISR&(1 << USISIF)));						//detection of start condition
	USISR |= (1 << USISIF);
}


void i2c_stop()
{
	USIDR = 0xFF;
	PORTB|=(1<<PB2);									//Pulling SDA high
	_delay_us(5);
	PORTB|=(1<<PB0);									//Pulling SCL low
	_delay_us(5);
	while(!(USISR&(1 << USIPF)));									//detection of stop condition
	USISR |= (1 << USIPF);
	sei();
}

void i2c_loadData(uint8_t data)
{
	USIDR = data;										//Load data to be sent to the USI data register
}

uint8_t i2c_transmitByte(uint8_t byt)
{
	uint8_t ack_bit = 0;
	i2c_loadData(byt);
	i2c_transfer();
	ack_bit = i2c_ack();
	
	return ack_bit;
}