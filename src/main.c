#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/button.h"
#include "../lib/i2c.h"
#include "../lib/lcd_i2c.h"

int main(void) {
    button_init();
    i2c_init();
    lcd_init();

    uint8_t speed = 0;  // Speed value 0-10

    lcd_set_cursor(0, 0);
    lcd_print("Motor Speed:");

    lcd_set_cursor(1, 0);
    lcd_print("0          ");

    while (1) {
        if (button_inc_pressed()) {
            if (speed < 10) speed++;

            // Wait for button release
            while (!(PIND & (1 << BTN_INC)));

            lcd_set_cursor(1, 0);
            // Print speed as single digit
            char buf[4];
            buf[0] = speed + '0';
            buf[1] = ' ';
            buf[2] = ' ';
            buf[3] = '\0';
            lcd_print(buf);
        }

        if (button_dec_pressed()) {
            if (speed > 0) speed--;

            // Wait for button release
            while (!(PIND & (1 << BTN_DEC)));

            lcd_set_cursor(1, 0);
            char buf[4];
            buf[0] = speed + '0';
            buf[1] = ' ';
            buf[2] = ' ';
            buf[3] = '\0';
            lcd_print(buf);
        }
    }
}