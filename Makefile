#Makefile for Static Library
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror -std=c99

.PHONY: clean

all: main

main: main.c mySimpleComputer.c mySimpleComputer.h myTerm.c myTerm.h
	$(CC) $(CFLAGS) main.c mySimpleComputer.c myTerm.c -o main