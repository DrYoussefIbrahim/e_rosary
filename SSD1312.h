/*
 * SSD1312.h
 *
 * Created: 21/11/2022 15:28:39
 *  Author: youss
 */ 


#ifndef SSD1312_H_
#define SSD1312_H_

#include "tinyTWI.h"
#include <avr/io.h>
#include "util/delay.h"
#include "font.c"

#define DISP_RESET 4

#define ADDRESS 0x78

#define ADRSSNG 0x20
#define SET_LINE 0x21
#define SET_PAGE 0x22
#define CONTRAST 0x81
#define INVERT_OFF 0xA6
#define INVERT_ON 0xA7
#define MULPX 0xA8
#define IREF 0xAD
#define DISP_OFF 0xAE
#define DISP_ON 0xAF
#define OFFSET 0xD3
#define CDIV 0xD5
#define PRECHG 0xD9
#define SET_SEG 0xDA
#define VCOMH 0xDB
#define D_NOP 0xE3
#define CHGPUMP 0x8D
#define C_LOCK 0xFD

#define frame 6;

uint8_t SSD1312_setReg(uint8_t reg, uint8_t val);
uint8_t SSD1312_sendCommand(uint8_t cmd);
void disp_init();
void SSD1312_splash();
void SSD1312_setRAM();
void SSD1312_clearBuf();
void SSD1312_printDigit(uint8_t num, uint8_t pos);
void SSD1312_printNum(long num);


#endif /* SSD1312_H_ */