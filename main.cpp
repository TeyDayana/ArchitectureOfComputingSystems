//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию, 
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib> // для функций rand() и srand()
#include <ctime>   // для функции time()  
#include <cstring>
#include "container.h"

void errMessage1() {
    printf("incorrect command line!\nWaited:\ncommand -f infile outfile01 outfile02\n"
        "Or:\ncommand -n number outfile01 outfile02\n");
}

void errMessage2() {
    printf("incorrect qualifier value!\nWaited:\ncommand -f infile outfile01 outfile02\n"
        "Or:\ncommand -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start");
    container c;
    Init(c);

    if (!strcmp(argv[1], "-f")) {
        FILE* file;
        file = fopen(argv[2], "r");
        In(c, file);
    }
    else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("incorrect numer of figures = %d. Set 0 < number <= 10000\n", size);
            return 3;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
        // Заполнение контейнера генератором случайных чисел
        InRnd(c, size);
    }
    else {
        errMessage2();
        return 2;
    }

    // Вывод содержимого контейнера в файл
    FILE* file1;
    file1 = fopen(argv[3], "w");
    fprintf(file1, "Filled container:\n");
    Out(c, file1);

    // Вывод 2й части задания
    FILE* file2;
    file2 = fopen(argv[4], "w");
    ProcessingVar23(c, file2);

    Clear(c);
    printf("\nFinished");
    return 0;
}
