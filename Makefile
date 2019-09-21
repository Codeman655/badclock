CC=g++
CFLAGS=

default: all

all: clocklib clock timetest

timetest: timetest.cpp

clocklib: clocklib.cpp
	$(CC) $(CFLAGS) -o clocklib clocklib.cpp

clock: clock.cpp
	$(CC) $(CFLAGS) -o clock clock.cpp

clean: 
	rm -rf *.dSYM *.o clocklib clock timetest

.PHONY: all clean
