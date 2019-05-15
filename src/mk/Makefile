#Makefile for myReadKey

CC = gcc

CFLAGS = -Wall -Werror -std=c99 
FLAGS = -o
BUILD = build/

all: build $(BUILD)mk.a

$(BUILD)mk.a: $(BUILD)myReadKey.o
	ar cr $(BUILD)mk.a $(BUILD)myReadKey.o

$(BUILD)myReadKey.o: myReadKey.c myReadKey.h
	$(CC) $(CFLAGS) -c myReadKey.c -o $@

build:
	mkdir build

clear:
	-rm -rf build