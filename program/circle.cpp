//------------------------------------------------------------------------------
// circle.cpp - содержит процедуры для работы с кругом
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "stdio.h"
#include "math.h"
#include "circle.h"

//------------------------------------------------------------------------------
// Ввод параметров круга из потока
void In(circle& c, FILE* file) {
    fscanf(file, "%d", &c.x_c);
    fscanf(file, "%d", &c.y_c);
    fscanf(file, "%d", &c.r);
}

// Случайный ввод параметров круга
void InRnd(circle& c) {
    c.x_c = Random();
    c.y_c = Random();
    c.r = Random();
}

//------------------------------------------------------------------------------
// Вывод параметров круга в поток
void Out(circle& c, FILE* file) {
    fprintf(file, "It is Circle. Center: x = %d, y = %d. Radius: r = %d. Perimeter = %f. Color: ",
        c.x_c, c.y_c, c.r, Perimeter(c));
}

//------------------------------------------------------------------------------
// Вычисление длины круга
double Perimeter(circle& c) {
    return 2 * M_PI * c.r;
}
