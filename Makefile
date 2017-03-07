SHELL = /bin/sh

SRCPATH = src/main.c
RESPATH = res/
BINPATH = bin/
OBJS = main
CFLAGS = `pkg-config --cflags gtk+-3.0`
CC = gcc
INCLUDE = 
LIBS = `pkg-config --libs gtk+-3.0`

compile:
	${CC} $(CFLAGS) ${INCLUDE} ${SRCPATH} -o ${BINPATH}${OBJS} ${LIBS} -rdynamic

clean:
	-rm -f *.o core *.core

run:
	./${BINPATH}${OBJS}

install:
	${CC}
