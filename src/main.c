#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "../lib/button.h"

int main(void) {
    button_init();

    // Use PB0 (pin 1) as indicator LED
    DDRB |= (1 << PB0);

    while (1) {
        if (button_inc_pressed()) {
            PORTB |= (1 << PB0);   // LED ON when INC pressed
        }
        if (button_dec_pressed()) {
            PORTB &= ~(1 << PB0);  // LED OFF when DEC pressed
        }
    }
}