CC=avr-gcc
CCHEX=avr-objcopy
FCPU=1600000
BAUD=9600

default: app.hex
app.o:  app.c
	$(CC) -g -Os -mmcu=atmega8 -c app.c -DF_CPU=$(FCPU)L -DBAUD=$(BAUD)U

app.elf: app.o
	$(CC) -g -mmcu=atmega8 -o app.elf app.o

app.hex: app.elf
	$(CCHEX) -j .text -j .data -O ihex app.elf app.hex

clean: 
	rm *.o *.elf *.hex

rebuild: clean app.hex


install:
	avrdude -patmega8 -cusbasp -Uflash:w:app.hex:i -P /dev/ttys00
