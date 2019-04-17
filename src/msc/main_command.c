#include "mySimpleComputer.h"

int main()
{
    sc_memoryInit();
    sc_memorySet(10, 5);
    sc_memorySet(45, 43);

    int buffer;
    sc_memoryGet(10, &buffer);
    printf("Ожидается: Адрес 10, значение 5\n");
    printf("Фактическое: Адрес %3d, значение %3d\n\n", 10, buffer);
    sc_memoryGet(43, &buffer);
    printf("Ожидается: Адрес 45, значение 43\n");
    printf("Фактическое: Адрес %3d, значение %3d\n", 45, buffer);

    int rgr;
    sc_regInit();
    rgr = sc_regGet(43, &rgr);
    printf("Проверка регистра\nОжидается: 2. Пофакту: %3d", rgr);

    //sc_memoryPrint();

    printf("\nСохранил файл.\nЗагрузил файл.\nВывод матрицы: ");
    sc_memorySave("file_bin/test.dat");
    sc_memoryLoad("file_bin/test.dat");
    //sc_memoryPrint();

    rgr = sc_commandEncode(WRITE, 10, &buffer);
    printf("Проверка комманд:\nКоманда с результатом: %3d, Значение:  %3d\n", rgr, buffer);

    int index = 10;
    int commande = WRITE;

    buffer = 16384;
    rgr = sc_commandDecode(buffer, &commande, &index);
    printf("Проверка Декодирования команды\nРезультат: %3d, Значение: %3d, Операнд: %3d\n", rgr, commande, index);
    sc_regGet(ERRORCOMS, &rgr);
    printf("Reg = %d", rgr);

    return 0;
}
