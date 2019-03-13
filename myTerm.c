#include "myTerm.h"

int mt_clrscr(void)
{
    printf("\E[H\E[J");
    return 0;
}
