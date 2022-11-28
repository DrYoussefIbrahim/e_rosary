/*
 * tinyTWI.h
 *
 * Created: 19/11/2022 15:27:00
 *  Author: youss
 */ 


#ifndef TINYTWI_H_
#define TINYTWI_H_

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"

uint8_t i2c_ack();
void i2c_transfer();
void i2c_start();
void i2c_init();
void i2c_stop();
void i2c_loadData(uint8_t data);
uint8_t i2c_transmitByte(uint8_t byt);


#endif /* TINYTWI_H_ */