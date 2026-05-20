# Motor Speed Control — ATmega16

Control a DC motor speed using two push buttons with speed displayed on I2C LCD.

## Hardware
- ATmega16A @ 8MHz internal
- L298N H-Bridge motor driver
- 16x2 I2C LCD (PCF8574T, address 0x27)
- 2x Push buttons (increment / decrement)
- DC motor

## Project Phases
- [x] Phase 1: LCD test
- [ ] Phase 2: Push buttons test
- [ ] Phase 3: LCD + buttons together
- [ ] Phase 4: Motor test
- [ ] Phase 5: Full integration

## Pin Map
| Function        | ATmega16 Pin |
|----------------|--------------|
| SCL (LCD)      | PC0 (Pin 22) |
| SDA (LCD)      | PC1 (Pin 23) |
| Button INC     | PD2 (Pin 16) |
| Button DEC     | PD3 (Pin 17) |
| Motor PWM      | PB3 (Pin 4)  |
| Motor IN1      | PD4 (Pin 18) |
| Motor IN2      | PD5 (Pin 19) |

## How to Build
make          # compile
make upload   # upload to ATmega16
make clean    # remove build files