#ifndef MYBIGCHAR_H
#define MYBIGCHAR_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h> 

#include "../mt/myTerm.h"
#include "../msc/mySimpleComputer.h"

#define EN_ACS "\E(0"
#define DS_ACS "\E(B"

#define upleft "l"
#define upright "k"
#define horiz "q"
#define vert "x"
#define downleft "m"
#define downright "j"

#define ACS_CKBOARD "a"
#define BC_SIZE_DEFAULT 2

int BC_SIZE;
int bigChar[2];
extern enum Color color;

int bc_box(int, int, int, int);
int bc_printA(char*);
int bc_printbigchar(int[], int, int, enum Color, enum Color);
int bc_setbigcharpos(int*, int, int, int);
int bc_getbigcharpos(int*, int, int, int*);
int bc_bigcharwrite(int, int*, int);
int bc_bigcharread(int, int*, int, int*); 
int bc_initBigChar(int*, char); 
#endif