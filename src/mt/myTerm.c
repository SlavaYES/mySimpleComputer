#include "myTerm.h"

int mt_clrscr(void) {

    printf("\E[H\E[J");
    return 0;
}

int mt_gotoXY(int x, int y) {

    printf("\E[%d;%dH", x, y);
    return 0;
}

int mt_getscreensize(int *rows, int *cols) {

    struct winsize ws;

    if (!ioctl(1, TIOCGWINSZ, &ws)) {
        *rows = ws.ws_row;
        *cols = ws.ws_col;
    } else {
        fprintf(stderr, "Error.\n");
        return -1;
    } return 0;
}

int mt_setfgcolor(enum Color color) {

    if ((int)color > -1 && (int)color < 8) {
        printf("\E[3%dm", color);
        return 0;
    } return -1;
}

int mt_setbgcolor(enum Color color) {

    if ((int)color > -1 && (int)color < 8) {
        printf("\E[4%dm", color);
        return 0;
    } return -1;
}
