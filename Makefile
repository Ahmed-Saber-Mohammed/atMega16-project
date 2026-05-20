MCU = atmega16
F_CPU = 8000000UL
CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude
PROGRAMMER = usbasp
PORT = usb

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -Wall

all: main.hex

main.elf: main.c i2c.c lcd_i2c.c
	$(CC) $(CFLAGS) -o main.elf main.c i2c.c lcd_i2c.c

main.hex: main.elf
	$(OBJCOPY) -O ihex -R .eeprom main.elf main.hex

upload: main.hex
	$(AVRDUDE) -c $(PROGRAMMER) -p m16 -P $(PORT) -B 5kHz -U flash:w:main.hex

clean:
	rm -f *.elf *.hex