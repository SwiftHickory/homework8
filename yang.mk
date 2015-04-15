# Makefile for yang.cpp

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: yang

yang: main.o myFunction.o earthquake.o station.o global.o event.o
	${CC} -o yang main.o myFunction.o earthquake.o station.o global.o event.o

main.o: main.cpp
	${CC} -c ${CFLAGS} main.cpp

myFunction.o: myFunction.cpp
	${CC} -c ${CFLAGS} myFunction.cpp

earthquake.o: earthquake.cpp
	${CC} -c ${CFLAGS} earthquake.cpp

global.o: global.cpp
	${CC} -c ${CFLAGS} global.cpp

station.o: station.cpp
	${CC} -c ${CFLAGS} station.cpp

event.o: event.cpp
	${CC} -c ${CFLAGS} event.cpp

clean:
	rm -rf *.o
