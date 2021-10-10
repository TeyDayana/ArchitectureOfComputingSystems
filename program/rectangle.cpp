//------------------------------------------------------------------------------
// rectangle.cpp - содержит процедуры для работы с прямоугольником
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "rectangle.h"

//------------------------------------------------------------------------------
// Ввод параметров прямоугольника из файла
void In(rectangle& r, FILE* file) {
    fscanf(file, "%d", &r.x_l_t);
    fscanf(file, "%d", &r.y_l_t);
    fscanf(file, "%d", &r.x_r_b);
    fscanf(file, "%d", &r.y_r_b);
}

// Случайный ввод параметров прямоугольника
void InRnd(rectangle& r) {
    r.x_l_t = Random();
    r.y_l_t = Random();
    do {
        r.x_r_b = Random();
    } while (r.x_r_b == r.x_l_t);
    do {
        r.y_r_b = Random();
    } while (r.y_r_b == r.y_l_t);
}

//------------------------------------------------------------------------------
// Вывод параметров прямоугольника в форматируемый поток
void Out(rectangle& r, FILE* file) {
    fprintf(file, "It is Rectangle. Left top point: x = %d, y = %d. Right bottom point: x = %d, y = %d. Perimeter = %f. Color: ",
        r.x_l_t, r.y_l_t, r.x_r_b, r.y_r_b, Perimeter(r));
}

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double Perimeter(rectangle& r) {
    int x = std::abs(r.x_l_t - r.x_r_b);
    int y = std::abs(r.y_l_t - r.y_r_b);
    return 2.0 * (x + y);
}
