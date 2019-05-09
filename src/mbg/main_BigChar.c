
#include "myBigChar.h"
#include "../mt/myTerm.h"
#include "../msc/mySimpleComputer.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>


int main()
{
    int n, m;
    int s[2] = {0xFF8080F8, 0x80808080}; 

    BC_SIZE = 2;

    int fd;
    int result;
    int c;

    mt_clrscr();
    mt_getscreensize(&n, &m);
    bc_box(10, 10, 10, 10);
    bc_box(30, 10, 10, 10);
    bc_box(50, 10, 10, 10);

    mt_gotoXY(13, 10); printf("Value");
    mt_gotoXY(33, 10); printf("File");
    mt_gotoXY(54, 10); printf("Bit");

    bc_initBigChar(s, '6');
    bc_printbigchar(s, 11, 11, DEFAULT, DEFAULT);

    fd = open("file_bin/test.txt", O_WRONLY);
    result = bc_bigcharwrite(fd, s, 1);
    printf("Result of writing: %d\n", result);
    close(fd);

    fd = open("file_bin/test.txt", O_RDONLY);
    result = bc_bigcharread(fd, s, 1, &c);
    bc_printbigchar(s, 10, 31, DEFAULT, DEFAULT);
    printf("Result: %d\n  c: %d\n  descryptor: %d\n", result, c, fd);
    close(fd);

    bc_setbigcharpos(s, 5, 3, 1);
    bc_setbigcharpos(s, 5, 4, 1);
	bc_printbigchar(s, 7, 51, DEFAULT, DEFAULT);
	bc_getbigcharpos(s, 5, 3, &c);
	printf("Value in [5, 3] = %d\n", c);
	bc_getbigcharpos(s, 5, 4, &c);
	printf("  Value in [5, 4] = %d\n", c);

    return 0;
}