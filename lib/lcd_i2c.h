#ifndef LCD_I2C_H
#define LCD_I2C_H

#include <avr/io.h>

#define LCD_ADDR 0x27   // Try 0x3F if this doesn't work

void lcd_init(void);
void lcd_clear(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print(const char *str);

#endif