#Makefile for Static Library

.PHONY: clean

all: main

main: main.c mySimpleComputer.h
	gcc -Werror -Wall main.c -o main