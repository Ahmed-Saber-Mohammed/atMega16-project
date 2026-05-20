#include "button.h"
#include <util/delay.h>

void button_init(void) {
    // Set PD2 and PD3 as input
    DDRD &= ~(1 << BTN_INC) & ~(1 << BTN_DEC);
    // Enable internal pull-up resistors
    PORTD |= (1 << BTN_INC) | (1 << BTN_DEC);
}

uint8_t button_inc_pressed(void) {
    if (!(PIND & (1 << BTN_INC))) {  // Active LOW (pull-up)
        _delay_ms(20);               // Debounce
        if (!(PIND & (1 << BTN_INC))) return 1;
    }
    return 0;
}

uint8_t button_dec_pressed(void) {
    if (!(PIND & (1 << BTN_DEC))) {  // Active LOW (pull-up)
        _delay_ms(20);               // Debounce
        if (!(PIND & (1 << BTN_DEC))) return 1;
    }
    return 0;
}