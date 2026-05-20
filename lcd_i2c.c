#include "lcd_i2c.h"
#include "i2c.h"
#include <util/delay.h>

#define RS  0
#define RW  1
#define EN  2
#define BL  3

static void lcd_write_4bits(uint8_t nibble, uint8_t rs) {
    uint8_t data = (nibble << 4) | (1 << BL);
    if (rs) data |= (1 << RS);

    // EN high
    i2c_start();
    i2c_write(LCD_ADDR << 1);
    i2c_write(data | (1 << EN));
    i2c_stop();
    _delay_us(1);

    // EN low
    i2c_start();
    i2c_write(LCD_ADDR << 1);
    i2c_write(data & ~(1 << EN));
    i2c_stop();
    _delay_us(50);
}

static void lcd_send_byte(uint8_t byte, uint8_t rs) {
    lcd_write_4bits(byte >> 4, rs);
    lcd_write_4bits(byte & 0x0F, rs);
}

void lcd_init(void) {
    _delay_ms(100);  // Wait for LCD power up

    // Special 4-bit init sequence
    lcd_write_4bits(0x03, 0); _delay_ms(10);
    lcd_write_4bits(0x03, 0); _delay_ms(10);
    lcd_write_4bits(0x03, 0); _delay_ms(10);
    lcd_write_4bits(0x02, 0); _delay_ms(10);

    // Function set: 4-bit, 2 lines, 5x8
    lcd_send_byte(0x28, 0); _delay_ms(1);
    // Display OFF
    lcd_send_byte(0x08, 0); _delay_ms(1);
    // Clear display
    lcd_send_byte(0x01, 0); _delay_ms(5);
    // Entry mode
    lcd_send_byte(0x06, 0); _delay_ms(1);
    // Display ON, cursor OFF
    lcd_send_byte(0x0C, 0); _delay_ms(1);
}

void lcd_clear(void) {
    lcd_send_byte(0x01, 0);
    _delay_ms(5);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t row_offsets[] = {0x00, 0x40};
    lcd_send_byte(0x80 | (row_offsets[row] + col), 0);
}

void lcd_print(const char *str) {
    while (*str) {
        lcd_send_byte(*str++, 1);
    }
}