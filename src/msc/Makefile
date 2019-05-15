#Makefile for mySimpleComputer

CC = gcc

CFLAGS = -Werror -Wall -std=c99
FLAGS = -o
BUILD = build/

all: build msca

msca: $(BUILD)main_command.o $(BUILD)msc.a
	$(CC) $(FLAGS) msca $(BUILD)main_command.o -L. $(BUILD)msc.a

$(BUILD)main_command.o: main_command.c
	$(CC) $(CFLAGS) -c main_command.c -o $@

$(BUILD)msc.a: $(BUILD)mySimpleComputer.o
	ar cr $(BUILD)msc.a $(BUILD)mySimpleComputer.o

$(BUILD)mySimpleComputer.o: mySimpleComputer.c mySimpleComputer.h
	$(CC) $(CFLAGS) -c mySimpleComputer.c -o $@

build:
	mkdir build
	
clear:
	-rm -rf build
	-rm msca