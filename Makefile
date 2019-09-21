CC=g++
CFLAGS= -g 

default: all

all: clocklib clock timetest

timetest: timetest.cpp

clocklib: 
	$(CC) $(CFLAGS) -o clocklib clocklib.cpp

clock: 
	$(CC) $(CFLAGS) -o clock clock.cpp

clean: 
	rm *.o clocklib clock

.PHONY: all clean
