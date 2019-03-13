#Makefile for Static Library

.PHONY: clean

all: main

main: main.c mySimpleComputer.c mySimpleComputer.h myTerm.c myTerm.h
	gcc -Werror -Wall main.c mySimpleComputer.c myTerm.c-o main