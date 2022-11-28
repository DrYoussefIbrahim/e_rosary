/*
 * SSD1312.c
 *
 * Created: 21/11/2022 15:28:50
 *  Author: youss
 */ 

#include "SSD1312.h"

uint8_t DRAM[360];

void SSD1312_clearBuf(){
	for(uint16_t i=0; i < 360; i++){
		DRAM[i] = 0x00;
	}
}

void SSD1312_splash(){
	for(uint16_t i=0; i < 360; i++){
		DRAM[i] = pgm_read_byte(splash + i);
	}
}

void SSD1312_printDigit(uint8_t num, uint8_t pos){
	if(num > 9 || pos > 5){
		return;
	}
	uint16_t ofst = (pos * 18) + frame;
	uint16_t fofst = num * 54;
	for(uint16_t section = 0; section < 3; section++){
		uint16_t memo = section * 120;
		uint16_t fmem = section * 18;
		memo += ofst;
		fmem += fofst;
		for(uint16_t i = 0; i < 18; i++){
			DRAM[memo + i] = pgm_read_byte(font + (fmem + i));
		}
	}
}

void SSD1312_printNum(long num){
	
	if(num > 999999){
		return;
	}
	
	SSD1312_clearBuf();
	uint8_t started = 0;
	
	if(num > 99999){
		SSD1312_printDigit(num/100000, 0);
		num %= 100000;
		started = 1;
	}
	
	if(num > 9999 || started==1){
		SSD1312_printDigit(num/10000, 1);
		num %= 10000;
		started = 1;
	}
	
	if(num > 999 || started==1){
		SSD1312_printDigit(num/1000, 2);
		num %= 1000;
		started = 1;
	}
	
	if(num > 99 || started==1){
		SSD1312_printDigit(num/100, 3);
		num %= 100;
		started = 1;
	}
	
	if(num > 9 || started==1){
		SSD1312_printDigit(num/10, 4);
		num %= 10;
		started = 1;
	}
	
	SSD1312_printDigit(num, 5);
	SSD1312_setRAM();
}

uint8_t SSD1312_setReg(uint8_t reg, uint8_t val){
	uint8_t confirmation = 0;
	SSD1312_sendCommand(reg);
	SSD1312_sendCommand(val);
	return confirmation;
}

uint8_t SSD1312_sendCommand(uint8_t cmd){
	uint8_t confirmation = 0;
	i2c_start();
	if(i2c_transmitByte(ADDRESS)==1){
		confirmation = i2c_transmitByte(0x00);
		confirmation = i2c_transmitByte(cmd);
	}
	i2c_stop();
	
	return confirmation;
}

uint8_t SSD1312_sendData(){
	uint8_t confirmation = 0;
	i2c_start();
	if(i2c_transmitByte(ADDRESS)==1){
		confirmation = i2c_transmitByte(0 | 1<<6);
	}
	
	return confirmation;
}

void SSD1312_setRAM(){
	for(uint8_t page = 0; page < 4; page++){
		SSD1312_sendCommand(0xB0 | (page+2));
		SSD1312_sendCommand(0);
		SSD1312_sendCommand(0x10);
		SSD1312_sendData();
		uint8_t temp = 0;
		switch(page){
			case 0:
			for(uint16_t s = 0; s < 120; s++){	
				i2c_transmitByte(DRAM[s] << 4);
			}
			break;
				
			case 1:
			for(uint16_t s = 0; s < 120; s++){
				temp |= (DRAM[s] >> 4) & 0b00001111;
				temp |= (DRAM[s + 120] << 4) & 0b11110000;
				i2c_transmitByte(temp);
				temp = 0;
			}
			break;
			
			case 2:
			for(uint16_t s = 120; s < 240; s++){
				temp |= (DRAM[s] >> 4) & 0b00001111;
				temp |= (DRAM[s + 120] << 4) & 0b11110000;
				i2c_transmitByte(temp);
				temp = 0;
			}
			break;
			
			case 3:
			for(uint16_t s = 240; s < 360; s++){
				i2c_transmitByte(DRAM[s] >> 4);
			}
			break;
			
			default:
			break;
		}
		i2c_stop();
	}
}


void disp_init(){
	SSD1312_clearBuf();
	PORTB |= (1<<DISP_RESET);
	DDRB |= (1<<DISP_RESET);
	
	// Display hardware reset
	_delay_ms(20);
	PORTB &= ~(1 << DISP_RESET);
	_delay_ms(10);
	PORTB |= (1 << DISP_RESET);
	_delay_ms(10);
	
	// Init sequence
	SSD1312_sendCommand(DISP_OFF);
	SSD1312_setReg(CDIV, 0xF0);
	SSD1312_setReg(MULPX, 46);
	SSD1312_setReg(OFFSET, 0);
	//SSD1312_sendCommand(0x40|18);
	//SSD1312_setReg(ADRSSNG, 0x02);
	SSD1312_sendCommand(0xA1);
	SSD1312_sendCommand(0xC0);
	SSD1312_setReg(CONTRAST, 0xFF);
	//SSD1312_setReg(PRECHG, 0x11);
	SSD1312_setReg(VCOMH, 0x30);
	SSD1312_setReg(CHGPUMP, 0x12);
	SSD1312_sendCommand(0xA6);
	SSD1312_setRAM();
	SSD1312_sendCommand(DISP_ON);
}