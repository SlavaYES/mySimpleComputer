#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

enum colors {
    WHITE = 15,
    BLACK = 0
};

int mt_clrscr(void); // Clear screen
int mt_gotoXY(int, int); // move X and Y
int mt_getscreensize(int *rows, int *cols);
int mt_setfgcolor(enum colors); // fill color text
int mt_setbgcolor(enum colors); // fill color background
