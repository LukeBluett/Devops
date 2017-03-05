SHELL = /bin/sh

SRCLOCATN = src/
RESLOCATN = res/
BINLOCATN = bin/
OBJS = main.o
CFLAG = -Wall -g
CC = gcc
INCLUDE = 
LIBS = -lm

install:${OBJ}
	${CC} ${CFLAGS} ${INCLUDE} - o $@ ${OBJS} ${LIBS}

clean:
	-rm -f *.o core *.core

run:
	./${BINLOCATN}${OBJS}
