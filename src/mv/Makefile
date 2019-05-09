#Makefile for myVisual

CC = gcc

CFLAGS = -Werror -Wall
FLAGS = -o
BUILD = build/

all: build $(BUILD)mv.a

$(BUILD)mv.a: $(BUILD)myVisual.o
	ar cr $(BUILD)mv.a $(BUILD)myVisual.o

$(BUILD)myVisual.o: myVisual.c myVisual.h
	$(CC) $(CFLAGS) -c myVisual.c -o $@

build:
	mkdir build

clear:
	-rm -rf build
	-rm -rf file_bin
	-rm mva