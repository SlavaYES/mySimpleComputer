#Makefile for myBigChar

CC = gcc

CFLAGS = -Werror -Wall
FLAGS = -o
BUILD = build/

all: build $(BUILD)mbg.a

$(BUILD)mbg.a: $(BUILD)myBigChar.o
	ar cr $(BUILD)mbg.a $(BUILD)myBigChar.o

$(BUILD)myBigChar.o: myBigChar.c myBigChar.h
	$(CC) $(CFLAGS) -c myBigChar.c -o $@

build:
	mkdir build file_bin

clear:
	-rm -rf build
	-rm -rf file_bin