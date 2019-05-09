#Makefile for Static Library
#СС указатель на компилятор для сборки
CC=gcc
#FLAGS Флажки для компиляции
CFLAGS=-Wall -Werror

.PHONY: clean

all: myComputer

myComputer: project src/main.o src/msc/build/msc.a src/mt/build/mt.a src/mbg/build/mbg.a src/mv/build/mv.a
	$(CC) src/main.o -L. src/msc/build/msc.a src/mt/build/mt.a src/mbg/build/mbg.a src/mv/build/mv.a -o $@

src/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o $@

project: 
	make msca
	make mta
	make mbga
	make mva

msca: 
	cd src/msc/ && make all

mta: 
	cd src/mt/ && make all

mbga: 
	cd src/mbg/ && make all
mva: 
	cd src/mv/ && make all

clear:
	-rm src/main.o
	cd src/msc/ && make clear
	cd src/mt/ && make clear
	cd src/mbg/ && make clear
	cd src/mv/ && make clear
	-rm myComputer