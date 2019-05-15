#ifndef MYTERM_H
#define MYTERM_H
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>

#define TERM "/dev/tty"

enum Color {
    BLACK  = 0,
    RED    = 1,
    GREEN  = 2,
    YELLOW = 3,
    BLUE   = 4,
    PURPLE = 5,
    CYAN   = 6,
    WHITE  = 7,
    DEFAULT = 9
};

int mt_clrscr(void); // Clear screen
int mt_gotoXY(int, int); // move X and Y
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum Color); // fill color text
int mt_setbgcolor(enum Color); // fill color background
#endif