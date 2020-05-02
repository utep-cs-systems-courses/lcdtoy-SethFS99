# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L../lib
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o
	$(AR) crs $@ $^

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h


button.elf: ${COMMON_OBJECTS} buzzer.o p1_interrupt_handler.o led.o LEDendme.o stateMachines.o switches.o wdInterruptHandler.o buttonMain.o ../lib/libTimer.a libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	msp430loader.sh button.elf

clean:
	rm -f *.o *.elf *~

buzzer.c:buzzer.h

wdInterruptHandler.o: stateMachines.h

stateMachines.o: stateMachines.h

drawOcto.elf:drawOcto.o libLcd.a
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@ -lTimer
loadOcto: drawOcto.elf
	msp430loader.sh $^
