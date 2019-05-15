#ifndef MYREADKEY_H
#define MYREADKEY_H

#include "../mt/myTerm.h"
#include "../mbg/myBigChar.h"

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>

enum Key {
	NONE, 	// 0
	F5, 	// 1
	F6,	 	// 2
	KLOAD, 	// 3
	SAVE, 	// 4
	RUN, 	// 5
	STEP, 	// 6
	RESET,	// 7
	EXIT, 	// 8
	UP, 	// 9
	LEFT, 	// 10
	RIGHT, 	// 11
	DOWN, 	// 12
	EDIT, 	// 13
	ENTER, 	// 14
	CONS 	// 15
};

int rk_readKey(enum Key *key);
int rk_myTermSave(struct termios *termState);
int rk_myTermRestore(struct termios *currState);
int rk_myTermRegime(struct termios *currState, int regime, int vtime, int vmin, int echo, int sigint);
void termInit();

#endif