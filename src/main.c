#include "msc/mySimpleComputer.h"
#include "mt/myTerm.h"
#include "mbg/myBigChar.h"
#include "mv/myVisual.h"
#include <string.h>

int sc_memoryPrint(int ,int);

int main() {

    int n, m;
    pointer_mem = 10;
    sc_memoryInit();
    sc_memorySet(pointer_mem, 37);
    sc_regInit();
    //sc_commandEncode(WRITE, 10, memory + 10);
    mt_getscreensize(&n, &m);

    mt_clrscr();
    bc_box(m / 5, n / 4, 62, 12);
    sc_memoryPrint(m / 5 + 1, n / 4 + 1);
    mt_gotoXY(m / 5 + 27, n/ 4);
    printf("Memory");

    int xx = m / 5 + 62 + 2, yy = n / 4;

    bc_box(m / 5 + 62 + 2, n / 4, 30, 3);
    mt_gotoXY(xx + 10 + 3, yy + 1);
    printf("+%04X", memory[10]);
    mt_gotoXY(xx + 10, yy);
    printf("Accumulator");

    bc_box(m / 5 + 62 + 2, n / 4 + 3, 30, 3);
    mt_gotoXY(xx + 10 + 3, yy + 4);
    printf("+0000");
    mt_gotoXY(xx + 6, yy + 3);
    printf("InstructionCounter");

    bc_box(m / 5 + 62 + 2, n / 4 + 6, 30, 3);
    mt_gotoXY(xx + 10 + 1, yy + 7);
    printf("+%02X : %02X", memory[10] / 100, memory[10] % 100);
    mt_gotoXY(xx + 11, yy + 6);
    printf("Operation");

    bc_box(m / 5 + 62 + 2, n / 4 + 9, 30, 3);
    mt_gotoXY(xx + 10 + 1, yy + 10);
    printf("A F C O F");
    mt_gotoXY(xx + 13, yy + 9);
    printf("Flags");
    outBigChar();

    return 0;
}
