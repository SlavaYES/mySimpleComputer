#Makefile for myTerminal

CC = gcc

CFLAGS = -Werror -Wall -std=c99
FLAGS = -o
BUILD = build/

all: build mta

mta: $(BUILD)main_terminal.o $(BUILD)mt.a
	$(CC) $(FLAGS) mta $(BUILD)main_terminal.o -L. $(BUILD)mt.a

$(BUILD)main_terminal.o: main_terminal.c
	$(CC) $(CFLAGS) -c main_terminal.c -o $@

$(BUILD)mt.a: $(BUILD)myTerm.o
	ar cr $(BUILD)mt.a $(BUILD)myTerm.o

$(BUILD)myTerm.o: myTerm.c myTerm.h
	$(CC) $(CFLAGS) -c myTerm.c -o $@

build:
	mkdir build
clear:
	-rm -rf build
	-rm mta