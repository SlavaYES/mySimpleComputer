#include "mySimpleComputer.h"

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
        sc_regSet(ERRORADD, 0);
        memory[address] = value;
        if (memory[address] == value) {
            return 0;
        }
    }
    sc_regSet(ERRORADD, 1);
    return ERRORADD;
}

int sc_memoryGet(int address, int *value)
{
    if (address >= 0 && address < N) {
        sc_regSet(ERRORADD, 0);
        *value = memory[address];
        return 0;
    }
    sc_regSet(ERRORADD, 1);
    return ERRORADD;
}

int sc_memorySave(char *filename)
{
    FILE *file;
    if (!(file = fopen(filename, "wb"))) {
        sc_regSet(ERRORFILE, 1);
        return ERRORFILE;
    }
    fwrite(memory, sizeof(int), N, file);
    
    sc_regSet(ERRORFILE, 0);
    fclose(file);
    return 0;
}

int sc_memoryLoad(char *filename)
{

    FILE *file;
    
    if (!(file = fopen(filename, "rd"))) {
        sc_regSet(ERRORFILE, 1);
        fclose(file);
        return ERRORFILE;
    }
    fread(memory, sizeof(int), N, file);
    
    fclose(file);
    sc_regSet(ERRORFILE, 0);
    return 0;
}

int sc_memoryPrint() 
{
    printf("\n\n    ");
    
    for (int i = 0; i < M; i++) {printf("%4d", i);} printf("\n");
    for (int i = 0; i < N; i++) {
        if (!(i%10)) {
            printf("\n%4d%4d", i/10, memory[i]);
        } else {
            printf("%4d", memory[i]);
        }
    } printf("\n");
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
        return 0;
    }

    sc_regSet(ERRORFLAG, 1);
    return ERRORFLAG;
}

int sc_checkCommand(int check_command)
{
    if (
        check_command == READ   ||
        check_command == WRITE  ||
        check_command == LOAD   ||
        check_command == STORE  ||
        check_command == ADD    ||
        check_command == SUB    ||
        check_command == DIVIDE ||
        check_command == MUL    ||
        check_command == JUMP   ||
        check_command == JNEG   ||
        check_command == JZ     ||
        check_command == HALT   ||
        check_command == NOT    ||
        check_command == AND    ||
        check_command == OR     ||
        check_command == XOR    ||
        check_command == JNS    ||
        check_command == JC     ||
        check_command == JNC    ||
        check_command == JP     ||
        check_command == JNP    ||
        check_command == CHL    ||
        check_command == SHR    ||
        check_command == RCL    ||
        check_command == RCR    ||
        check_command == NEG    ||
        check_command == ADDC   ||
        check_command == SUBC   ||
        check_command == LOGLC  ||
        check_command == LOGRC  ||
        check_command == RCCL   ||
        check_command == RCCR   ||
        check_command == MOVA   ||
        check_command == MOVR   ||
        check_command == MOVCA  ||
        check_command == MOVCR) {
        return 1;
    }
    return 0;
}

int sc_commandEncode(int command, int operand, int *value)
{
    if (sc_checkCommand(command) && operand < N) {
        sc_regSet(ERRORCOMS, 0);
        *value = (*value) & 0;
        *value = (*value) | command;
        *value = (*value) << 7;
        *value = (*value) | operand;
        return 0;
    }
    sc_regSet(ERRORCOMS, 1);
    return ERRORCOMS;
}

int sc_commandDecode(int value, int *command, int *operand)
{
    int buffer;
    buffer = (value >> 7) & BIT7;
    if ((value >> 14) == 1) { 
        sc_regSet(ERRORCOMS, 1);
        return ERRORCOMS;
    }
    if (sc_checkCommand(buffer)) {
        sc_regSet(ERRORCOMS, 0);
        *command = buffer;
        buffer = value & BIT7;
        if (buffer < 100) {
            *operand = buffer;
        } else {
            *command = -1;
            *operand = -1;
            sc_regSet(ERROROPER, 1);
            return ERROROPER;
        }
        return 0;
    }
    sc_regSet(ERROROPER, 1);
    return ERROROPER;
}
