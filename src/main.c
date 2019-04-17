#include "msc/mySimpleComputer.h"
#include "mt/myTerm.h"
#include <string.h>

#define EN_ACS "\E(0"
#define DS_ACS "\E(B"

#define upleft "l"
#define upright "k"
#define horiz "q"
#define vert "x"
#define downleft "m"
#define downright "j"

void board(int, int, int, int);
void printb(char*);
int sc_memoryPrint(int ,int);

int main() {

    int n, m;
    sc_memoryInit();
    sc_memorySet(10, 34);
    sc_regInit();
    sc_commandEncode(WRITE, 10, memory + 10);
    mt_getscreensize(&n, &m);

    mt_clrscr();
    board(m / 5, n / 4, 72, 12);
    sc_memoryPrint(m / 5 + 1, n / 4 + 1);
    mt_gotoXY(m / 5 + 34, n/ 4);
    printf("Memory");

    int xx = m / 5 + 72 + 2, yy = n / 4;

    board(m / 5 + 72 + 2, n / 4, 30, 3);
    mt_gotoXY(xx + 10 + 3, yy + 1);
    printf("+%d", memory[10]);
    mt_gotoXY(xx + 10, yy);
    printf("Accumulator");

    board(m / 5 + 72 + 2, n / 4 + 3, 30, 3);
    mt_gotoXY(xx + 10 + 3, yy + 4);
    printf("+0000");
    mt_gotoXY(xx + 6, yy + 3);
    printf("InstructionCounter");

    board(m / 5 + 72 + 2, n / 4 + 6, 30, 3);
    mt_gotoXY(xx + 10 + 1, yy + 7);
    printf("+%d : %d", memory[10] / 100, memory[10] % 100);
    mt_gotoXY(xx + 11, yy + 6);
    printf("Operation");

    board(m / 5 + 72 + 2, n / 4 + 9, 30, 3);
    mt_gotoXY(xx + 10 + 1, yy + 10);
    printf("A F C O F");
    mt_gotoXY(xx + 13, yy + 9);
    printf("Flags");

    mt_gotoXY(0, m);
    return 0;
}

void printb(char *ch) {

    printf(EN_ACS);
    printf(ch);
    printf(DS_ACS);
}

void board(int x, int y, int dx, int dy) {

    mt_gotoXY(x, y);
    printb(upleft);

    for (int i = 0; i < dx - 2; i++) {
        printb(horiz);
    }

    printb(upright);
    for (int i = 1; i <= dy - 2; i++) {
        mt_gotoXY(x, y + i);
        printb(vert);
        mt_gotoXY(x + dx - 1, y + i);
        printb(vert);
    }

    mt_gotoXY(x, y + dy - 1);
    printb(downleft);
    for (int i = 0; i < dx - 2; i++) {
        printb(horiz);
    }
    printb(downright);
}

int sc_memoryPrint(int x, int y)
{
    mt_gotoXY(x, y);
    for (int i = 0; i < M; i++) {
        mt_gotoXY(x, y + i);
        for (int j = 0; j < M; j++) {
            if (memory[i * 10 + j] / 1000 > 0) {
                mt_setbgcolor(WHITE); mt_setfgcolor(BLACK);
                printf(" +%4d ", memory[i * 10 + j]);
                mt_setbgcolor(BLACK); mt_setfgcolor(WHITE);
            } else if (memory[i * 10 + j] / 100 > 0) {
                printf(" +0%3d ", memory[i * 10 + j]);
            } else if (memory[i * 10 + j] / 10 > 0) {
                printf(" +00%2d ", memory[i * 10 + j]);
            } else if (memory[i * 10 + j] / 1 > 0) {
                printf(" +000%1d ", memory[i * 10 + j]);
            } else {
                printf(" +0000 ");
            }
        }
        printf("\n\n");
    }

    return 0;
}
