//------------------------------------------------------------------------------
// triangle.cpp - содержит процедуры для работы с треугольником
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void Triangle::In(FILE* file) {
    fscanf(file, "%d", &x_1);
    fscanf(file, "%d", &y_1);
    fscanf(file, "%d", &x_2);
    fscanf(file, "%d", &y_2);
    fscanf(file, "%d", &x_3);
    fscanf(file, "%d", &y_3);
}

// Случайный ввод параметров треугольника
void Triangle::InRnd() {
    int a, b, c, x, y;
    do {
        x_1 = Shape::rnd20.Get();
        y_1 = Shape::rnd20.Get();
        x_2 = Shape::rnd20.Get();
        y_2 = Shape::rnd20.Get();
        x_3 = Shape::rnd20.Get();
        y_3 = Shape::rnd20.Get();

        x = std::abs(x_1 - x_2);
        y = std::abs(y_1 - y_2);
        a = sqrt(x * x + y * y);

        x = std::abs(x_2 - x_3);
        y = std::abs(y_2 - y_3);
        b = sqrt(x * x + y * y);

        x = std::abs(x_3 - x_1);
        y = std::abs(y_3 - y_1);
        c = sqrt(x * x + y * y);
    } while (a >= b + c || b >= a + c || c >= a + b);
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Triangle::Out(FILE* file) {
    fprintf(file, "It is Triangle. A-point: x = %d, y = %d. B-point: x = %d, y = %d. C-point: x = %d, y = %d. Perimeter = %f. Color: ",
            x_1, y_1, x_2, y_2, x_3, y_3, Perimeter());
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Triangle::Perimeter() {
    int x, y;
    x = std::abs(x_1 - x_2);
    y = std::abs(y_1 - y_2);
    double a = sqrt(x * x + y * y);

    x = std::abs(x_2 - x_3);
    y = std::abs(y_2 - y_3);
    double b = sqrt(x * x + y * y);

    x = std::abs(x_3 - x_1);
    y = std::abs(y_3 - y_1);
    double c = sqrt(x * x + y * y);
    return a + b + c;
}