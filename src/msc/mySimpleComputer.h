#ifndef MYSIMPLECOMPUTER_H
#define MYSIMPLECOMPUTER_H
#include <stdio.h>
#define N 100
#define M 10

#define ERRORADD  1
#define ERRORFLAG 2
#define ERRORFILE 3
#define ERRORCOMS 4
#define ERROROPER 5
#define IGNORTACT 6

#define BIT7 0x7f
#define BIT8 0xff

int memory[N];
int registr;

enum com {

    // INPUT/OUTPUT
    READ  = 0x10,
    WRITE = 0x11,

    // LOAD/STORE IT ACCUMULATOR
    LOAD  = 0x20,
    STORE = 0x21,

    // ARITHMETIC OPERATIONS
    ADD    = 0x30,
    SUB    = 0x31,
    DIVIDE = 0x32,
    MUL    = 0x33,

    // OPERATIONS BROADCAST CONTROL
    JUMP = 0x40,
    JNEG = 0x41,
    JZ   = 0x42,
    HALT = 0x43,

    // USER FUNCTUON
    NOT   = 0x51,
    AND   = 0x52,
    OR    = 0x53,
    XOR   = 0x54,
    JNS   = 0x55,
    JC    = 0x56,
    JNC   = 0x57,
    JP    = 0x58,
    JNP   = 0x59,
    CHL   = 0x60,
    SHR   = 0x61,
    RCL   = 0x62,
    RCR   = 0x63,
    NEG   = 0x64,
    ADDC  = 0x65,
    SUBC  = 0x66,
    LOGLC = 0x67,
    LOGRC = 0x68,
    RCCL  = 0x69,
    RCCR  = 0x70,
    MOVA  = 0x71,
    MOVR  = 0x72,
    MOVCA = 0x73,
    MOVCR = 0x74
};

// Memory //

int sc_memoryInit(); // Initialization array memory

int sc_memorySet(int address, int value); // Set value to address

int sc_memoryGet(int address, int *value); // Get value of address

int sc_memorySave(char *filename); // Save to file in binary view

int sc_memoryLoad(char *filename); // Load of file RAM

// Register //

int sc_regInit(void); // It initializaion register of flags zero value

int sc_regSet(int flag, int value); // sets the value of the flag register

int sc_regGet(int flag, int *value); // gets the value of the flag

// Command //

int sc_checkCommand(int command);

int sc_commandEncode(int command, int operand, int *value); // encodes a command with the specified number and operand and put result in Value

int sc_commandDecode(int value, int *command, int *operand); // decodes the value that command SC

//

int sc_accumGet(int *value);

int sc_accumSet(int value);

int sc_countGet(int *value);

int sc_countSet(int value);

int sc_countInkrement();

#endif

