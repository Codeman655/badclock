CC=g++
CFLAGS=-static

all: clocklib clock

timetest: timetest.cpp

clocklib: clocklib.o
	$(CC) -o clocklib clocklib.o

clock: clock.o
	$(CC) -o clock clock.o

clean: 
	rm *.o clocklib clock

.PHONY: all clean
