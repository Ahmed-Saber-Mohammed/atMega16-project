#ifndef BUTTON_H
#define BUTTON_H

#include <avr/io.h>

#define BTN_INC PD2   // Pin 16 - increment speed
#define BTN_DEC PD3   // Pin 17 - decrement speed

void button_init(void);
uint8_t button_inc_pressed(void);
uint8_t button_dec_pressed(void);

#endif