#Makefile for Static Library
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror -std=c99

.PHONY: clean

all: myComputer

myComputer: project src/main.o src/msc/build/msc.a src/mt/build/mt.a
	$(CC) src/main.o -L. src/msc/build/msc.a src/mt/build/mt.a -o $@

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $@

project: 
	make msca
	make mta

msca: 
	cd src/msc/ && make all

mta: 
	cd src/mt/ && make all

clear:
	-rm src/main.o
	cd src/msc/ && make clear
	cd src/mt/ && make clear
	-rm myComputer