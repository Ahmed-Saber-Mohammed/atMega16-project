#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "i2c.h"
#include "lcd_i2c.h"

int main(void) {
    i2c_init();
    lcd_init();

    lcd_set_cursor(0, 0);
    lcd_print("Good morning");

    lcd_set_cursor(1, 0);
    lcd_print("Moamen Ayman");

    while (1) {}
}