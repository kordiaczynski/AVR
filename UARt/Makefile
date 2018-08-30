CC=avr-gcc
FCPU=1600000
BAUD=9600
default: main.hex



uart.o: uart.c
	$(CC) -g -Os -mmcu=atmega8 -c uart.c -DF_CPU=$(FCPU)L -DBAUD=$(BAUD)U

main.o: main.c
	$(CC) -g -Os -mmcu=atmega8 -c main.c -DF_CPU=$(FCPU)L -DBAUD=$(BAUD)U

sender.o: sender.c
	$(CC) -g -Os -mmcu=atmega8 -c sender.c -DF_CPU=$(FCPU)L -DBAUD=$(BAUD)U

senderReady.o: uart.o sender.o
	avr-ld -r uart.o sender.o -o senderReady.o

mainReady.o: uart.o main.o
	avr-ld -r uart.o main.o -o mainReady.o

main.elf: mainReady.o
	$(CC) -g -mmcu=atmega8 -o main.elf mainReady.o

sender.elf: senderReady.o
	$(CC) -g -mmcu=atmega8 -o sender.elf senderReady.o

main.hex: main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex

sender.hex: sender.elf
	avr-objcopy -j .text -j .data -O ihex sender.elf sender.hex


sender: sender.hex
	ls

installReceiver: main.hex
	avrdude -patmega8 -cusbasp -Uflash:w:main.hex:i -P /dev/ttys00

installSender: sender.hex
	avrdude -patmega8 -cusbasp -Uflash:w:sender.hex:i -P /dev/ttys00


clean:
	rm *.hex *.o *.elf

rebuildReceiver: clean installReceiver

rebuildSender: clean installSender
