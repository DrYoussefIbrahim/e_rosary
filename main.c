/*
 * e_rosary.c
 *
 * Created: 10/11/2022 15:04:17
 * Author : youss
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
//#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include "util/delay.h"
#include "tinyTWI.h"
#include "SSD1312.h"

#define BUTTON 3
#define RESET_BUTTON() PCMSK |= 1 << BUTTON;\
pressed = 0;

#define R_DELAY 100
#define S_DELAY 350

volatile uint8_t pressed = 0;
volatile long ticks = 0;

void io_init();
void interrupts_init();
void timers_init();
void sleep();

ISR(PCINT0_vect){
	if(PINB & 1<<BUTTON){
		PCMSK &= ~(1<<BUTTON);
		pressed = 1;	
	}
}

ISR(TIMER0_OVF_vect){
	ticks++;
}

int main(void)
{
	i2c_init();
	interrupts_init();
	timers_init();
	_delay_ms(1000);
	disp_init();
	_delay_ms(10);
    long count = 0;
	SSD1312_splash();
	SSD1312_setRAM();
	_delay_ms(2000);
	SSD1312_printNum(count);
    while (1) 
    {
		if(pressed == 1){
			ticks = 0;
			if(count == 999999){
				count = 0;
			} else {
				count++;
			}
			SSD1312_printNum(count);
			_delay_ms(5);
			while(PINB & 1<<BUTTON){
				if(ticks == R_DELAY){
					count = 0;
					SSD1312_printNum(count);
				}
			}
			_delay_ms(5);
			ticks = 0;
			RESET_BUTTON();
		}
		
		if(ticks == S_DELAY){
			sleep();
		}
		
    }
}


void interrupts_init(){
	GIMSK = 1 << PCIE;
	PCMSK |= 1 << BUTTON;
	sei(); // Enable global interrupts
}

void timers_init(){
	TCCR0A = 0;
	TCCR0B = 0b00000101;
	TIMSK =  0b00000010;
}

void sleep() {
	SSD1312_sendCommand(DISP_OFF);
	DDRB = 0;
	PORTB = 0;
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	cli();
	power_all_disable();
	sleep_enable();
	sleep_bod_disable();
	RESET_BUTTON();
	sei();
	sleep_cpu();
	sleep_disable();
	power_all_enable();
	i2c_init();
	disp_init();
	SSD1312_sendCommand(DISP_ON);
}

