/*
* font.c
*
* Created: 27/11/2022 11:54:12
*  Author: youss
*/

#include <avr/pgmspace.h>

const static uint8_t font[540] PROGMEM = {0x00, 0b11011000, 0b11011100, 0b11011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Zero
										  0x00, 0b11110111, 0b11110111, 0b11100011, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00011011, 0b00111011, 0b01111011, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // One
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b00011000, 0b00011100, 0b00011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Two
										  0x00, 0b11110000, 0b11110000, 0b11100000, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b00000110, 0b00000111, 0b00000111, 0b00000111, 0x00,
										  0x00, 0b00011011, 0b00111011, 0b01111011, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01000000, 0b00000000, 0b00000000, 0b00000000, 0x00,
										  
										  0x00, 0b00011000, 0b00011100, 0b00011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Three
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00011000, 0b00111000, 0b01111000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b11000000, 0b11000000, 0b11000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Four
										  0x00, 0b00000111, 0b00000111, 0b00000011, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b11011000, 0b11011100, 0b11011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0x00, // Five
										  0x00, 0b00000111, 0b00000111, 0b00000011, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000000, 0b11110000, 0b11110000, 0b11110000, 0x00,
										  0x00, 0b00011000, 0b00111000, 0b01111000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b11011000, 0b11011100, 0b11011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0x00, // Six
										  0x00, 0b11110111, 0b11110111, 0b11100011, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000000, 0b11110000, 0b11110000, 0b11110000, 0x00,
										  0x00, 0b00011011, 0b00111011, 0b01111011, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b00011000, 0b00011100, 0b00011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Seven
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b11011000, 0b11011100, 0b11011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Eight
										  0x00, 0b11110111, 0b11110111, 0b11100011, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00011011, 0b00111011, 0b01111011, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00,
										  
										  0x00, 0b11011000, 0b11011100, 0b11011110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00001110, 0b00000110, 0b00000010, 0b00001000, 0b00001100, 0b11111110, 0b11111110, 0b11111110, 0x00, // Nine
										  0x00, 0b00000111, 0b00000111, 0b00000011, 0b00001000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00111000, 0b00110000, 0b10000110, 0b11110111, 0b11110111, 0b11110111, 0x00,
										  0x00, 0b00011000, 0b00111000, 0b01111000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01110000, 0b01100000, 0b01001111, 0b00011111, 0b00111111, 0b00000000, 0x00};
										  

const static uint8_t splash[360] PROGMEM = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b11000000, 0b10000000, 0, 0, 0b01110000, 0b11100000, 0b10000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b11000000, 0b10000000, 0, 0, 0b01110000, 0b11100000, 0b10000000, 0, 0, 0, 0, 0, 0b00110000, 0b00100000, 0b00110000, 0b00100000, 0b00110000, 0, 0b11000000, 0b10000000, 0, 0, 0b01110000, 0b11100000, 0b10000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b10000000, 0b11000000, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0b11110000, 0b11111000, 0b11011000, 0b11011100, 0b11011100, 0b11111000, 0b11111000, 0b11000000, 0b11000000, 0b11000000, 0b11000000, 0b11111000, 0b11110000, 0b11000000, 0b11000000, 0b11011000, 0b11001100, 0b11000110, 0b11000110, 0b01000110, 0b01111100, 0b00111000, 0b00010000, 0, 0b01110000, 0b11110000, 0b11100000, 0b01111111, 0b00111111, 0, 0, 0b01111111, 0b00111111, 0, 0, 0b11000000, 0b11000000, 0b00010000, 0b00111000, 0b00010000, 0, 0b00110000, 0b01110000, 0b11100000, 0b11000000, 0b11000000, 0b11100000, 0b10110000, 0b10011000, 0b10110000, 0b11100000, 0b11000000, 0b11000000, 0b11011000, 0b11001100, 0b11000110, 0b11000110, 0b01000110, 0b01111100, 0b00111000, 0b00010000, 0, 0b01110000, 0b11110000, 0b11100000, 0b01111111, 0b00111111, 0, 0, 0b01111111, 0b00111111, 0, 0, 0b00011000, 0b00111100, 0b00101100, 0b01111100, 0b11100000, 0b11100000, 0b11111111, 0b11111100, 0b11110000, 0b01111111, 0b00111111, 0, 0, 0, 0b01111111, 0b00111111, 0, 0, 0b11111000, 0b11111100, 0b01101100, 0b01101110, 0b01101110, 0b00111100, 0b00111100, 0b00110000, 0b00111100, 0b00111000, 0b00110000, 0b00111100, 0b00110000, 0b00111110, 0b00111100, 0b10110000, 0b00110000, 0b00111000, 0b00011111, 0b00011111, 0, 0, 0, 0,
											0, 0, 0, 0, 0, 0b00000111, 0b00001111, 0, 0, 0, 0, 0, 0b00000100, 0b00001110, 0b00000100, 0b00001110, 0b00000100, 0, 0, 0, 0, 0, 0, 0, 0, 0b00001000, 0b00001100, 0b00001100, 0b00001100, 0b00000110, 0b00000011, 0b00000001, 0, 0, 0, 0, 0, 0, 0, 0, 0b00000011, 0b00001111, 0b00001100, 0b00011100, 0b00011100, 0b00011100, 0b00001100, 0b00001110, 0b00000011, 0, 0, 0, 0, 1, 1,0, 0, 0, 0, 0, 0, 0, 0, 0, 0b00001000, 0b00001100, 0b00001100, 0b00000110, 0b00000011, 0b00000001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b00000011, 0b00000111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0b00000001, 0b00000011, 0b00000001, 0, 0, 0, 0, 0, 0, 0};