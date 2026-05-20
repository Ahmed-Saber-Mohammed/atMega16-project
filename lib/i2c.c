#include "i2c.h"
#include <util/twi.h>

void i2c_init(void) {
    // Set I2C clock to 100kHz with 8MHz CPU clock
    TWSR = 0x00;       // Prescaler = 1
    TWBR = 32;         // ((8000000 / 100000) - 16) / 2 = 32
    TWCR = (1 << TWEN);
}

void i2c_start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

uint8_t i2c_write(uint8_t data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TW_STATUS;
}