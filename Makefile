SHELL = /bin/sh

GITFILES = Makefile src/*.c res/*.glade 
SRCPATH = src/main.c
RESPATH = res/
BINPATH = bin/
OBJS = main
CFLAGS = `pkg-config --cflags gtk+-3.0`
CC = gcc
ADD = git add
COMMIT = git commit
INCLUDE = 
LIBS = `pkg-config --libs gtk+-3.0` -I /usr/include/postgresql -lpq -std=c99

compile:
	${CC} $(CFLAGS) ${INCLUDE} ${SRCPATH} -o ${BINPATH}${OBJS} ${LIBS} -rdynamic

clean:
	-rm -f *.o core *.core

run:
	./${BINPATH}${OBJS}

git:
	${ADD} ${GITFILES} 
	${COMMIT}

install:
	${CC}
