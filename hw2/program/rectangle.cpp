//------------------------------------------------------------------------------
// rectangle.cpp - содержит процедуры для работы с прямоугольником
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла

void Rectangle::In(FILE* file) {
    fscanf(file, "%d", &x_l_t);
    fscanf(file, "%d", &y_l_t);
    fscanf(file, "%d", &x_r_b);
    fscanf(file, "%d", &y_r_b);
}

// Случайный ввод параметров прямоугольника
void Rectangle::InRnd() {
    x_l_t = Shape::rnd20.Get();
    y_l_t = Shape::rnd20.Get();
    do {
        x_r_b = Shape::rnd20.Get();
    } while (x_r_b == x_l_t);
    do {
        y_r_b = Shape::rnd20.Get();
    } while (y_r_b == y_l_t);
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Rectangle::Out(FILE* file) {
    fprintf(file, "It is Rectangle. Left top point: x = %d, y = %d. Right bottom point: x = %d, y = %d. Perimeter = %f. Color: ",
            x_l_t, y_l_t, x_r_b, y_r_b, Perimeter());
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Rectangle::Perimeter() {
    int x = std::abs(x_l_t - x_r_b);
    int y = std::abs(y_l_t - y_r_b);
    return 2.0 * (x + y);
}