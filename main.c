#include "mySimpleComputer.h"
#include <stdio.h>

// Memory //

int sc_memoryInit(); // Initialization array memory

int sc_memorySet(int address, int value); // Set value to address

int sc_memoryget(int address, int *value); // Get value of address

int sc_memorySave(char *filename); // Save to file in binary view

int sc_memoryLoad(char *filename); // Load of file RAM

// Register //

int sc_regInt(void); // It initializaion register of flags zero value

int sc_regSet(int flag, int value); // sets the value of the flag register

int sc_regGet(int flag, int *value); // gets the value of the flag

// Command //

int sc_commandEncode(int command, int operand, int *value); // encodes a command with the specified number and operand and put result in Value

int sc_commandDecode(int value, int *command, int *operand); // decodes the value that command SC

//



int main()
{
    sc_memoryInit();

    return 0;
}

int sc_memoryInit()
{
    for (int i = 0; i < N; i++) {
        memory[i] = 0x0;
    }

    return 0;
}

int sc_memorySet(int address, int value)
{
    if (address >= 0  && address < N) {
        // set to memory;
    }
    
    return ERRORADD;
}

int sc_memoryGet(int address, int *value)
{
    //
    if (address >= 0 && address < N) {
        // get to address
    }
    return ERRORADD;
}

int sc_memorySave(char *filename)
{
    
    // function write/fwrite in binary view
    
    return 0;
}

int sc_memoryLoad(char *filename)
{

    // function read/fread

    return 0;
}

int sc_regInit(void)
{
    registr = registr & 0;

    return 0;
}

int sc_regSet(int flag, int value)
{
    if (flag >= 0 && flag < 32) {
        if (value == 0) {
            registr = registr & (~(1 << flag));
        } else if (value == 1) {
            registr = registr | (1 << flag);
        } else {
            return -1;
        }
        return 0;
    }

    sc_regSet(ERRORFLAG, 1);
    return ERRORFLAG;
}

int sc_regGet(int flag, int *value)
{
    if (flag >= 0 && flag < 31) {
        *value = (registr >> flag) & 0x1;
    }
    // get to flag
    sc_regSet(ERRORFLAG, 1);
    return ERRORFLAG;
}

int sc_commandEncode(int command, int operand, int *value)
{
    
    return 0;
}

int sc_commandDecode(int value, int *command, int *operand)
{

    return 0;
}
















