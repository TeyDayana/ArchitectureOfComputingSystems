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
void Circle::In(FILE* file) {
    fscanf(file, "%d", &x_c);
    fscanf(file, "%d", &y_c);
    fscanf(file, "%d", &r);
}

// Случайный ввод параметров круга
void Circle::InRnd() {
    x_c = Shape::rnd20.Get();
    y_c = Shape::rnd20.Get();
    r = Shape::rnd20.Get();
}

//------------------------------------------------------------------------------
// Вывод параметров круга в поток
void Circle::Out(FILE* file) {
    fprintf(file, "It is Circle. Center: x = %d, y = %d. Radius: r = %d. Perimeter = %f. Color: ",
            x_c, y_c, r, Perimeter());
}

//------------------------------------------------------------------------------
// Вычисление длины круга
double Circle::Perimeter() {
    return 2 * M_PI * r;
}