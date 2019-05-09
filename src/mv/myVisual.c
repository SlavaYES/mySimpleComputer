#include "myVisual.h"
#include "../mt/myTerm.h"
#include "../mbg/myBigChar.h"

void outBigChar(void)
{
    int value;
    char ss[8];

    bc_box(42, 27, 46, 10);
    sc_memoryGet(pointer_mem, &value);

    if ((value >> 14)) {
		value = value & 0x3fff;
		sprintf(ss, "-%04X", value);
	}
	else {
		sprintf(ss, "+%04X", value);
	}
	for (int i = 0; i < 5; i++){
		bc_initBigChar(bigChar, ss[i]);
		bc_printbigchar(bigChar, 28, 43 + i * 9, DEFAULT, DEFAULT);
	}

}

int sc_memoryPrint(int x, int y)
{
    mt_gotoXY(x, y);
    for (int i = 0; i < M; i++) {
        mt_gotoXY(x, y + i);
        for (int j = 0; j < M; j++) {
            printf("+%04X ", memory[i * 10 + j]);
        }
    }

    return 0;
}