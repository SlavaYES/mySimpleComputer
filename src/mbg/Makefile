#Makefile for myBigChar

CC = gcc

CFLAGS = -Wall -Werror -std=c99
FLAGS = -o
BUILD = build/

all: build mbga

mbga: $(BUILD)main_BigChar.o $(BUILD)mbg.a 
	$(CC) $(FLAGS) mbga $(BUILD)main_BigChar.o -L. $(BUILD)mbg.a ../mt/build/mt.a ../msc/build/msc.a

$(BUILD)main_BigChar.o: main_BigChar.c
	$(CC) $(CFLAGS) -c main_BigChar.c -o $@

$(BUILD)mbg.a: $(BUILD)myBigChar.o
	ar cr $(BUILD)mbg.a $(BUILD)myBigChar.o

$(BUILD)myBigChar.o: myBigChar.c myBigChar.h
	$(CC) $(CFLAGS) -c myBigChar.c -o $@

build:
	mkdir build file_bin
	touch file_bin/test.txt

clear:
	-rm -rf build
	-rm -rf file_bin
	-rm mbga