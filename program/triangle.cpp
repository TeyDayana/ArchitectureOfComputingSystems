//------------------------------------------------------------------------------
// triangle.cpp - содержит процедуры для работы с треугольником
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "math.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Ввод параметров треугольника из потока
void In(triangle& t, FILE* file) {
    fscanf(file, "%d", &t.x_1);
    fscanf(file, "%d", &t.y_1);
    fscanf(file, "%d", &t.x_2);
    fscanf(file, "%d", &t.y_2);
    fscanf(file, "%d", &t.x_3);
    fscanf(file, "%d", &t.y_3);
}

// Случайный ввод параметров треугольника
void InRnd(triangle& t) {
    int a, b, c, x, y;
    do {
        t.x_1 = Random();
        t.y_1 = Random();
        t.x_2 = Random();
        t.y_2 = Random();
        t.x_3 = Random();
        t.y_3 = Random();

        x = std::abs(t.x_1 - t.x_2);
        y = std::abs(t.y_1 - t.y_2);
        a = sqrt(x * x + y * y);

        x = std::abs(t.x_2 - t.x_3);
        y = std::abs(t.y_2 - t.y_3);
        b = sqrt(x * x + y * y);

        x = std::abs(t.x_3 - t.x_1);
        y = std::abs(t.y_3 - t.y_1);
        c = sqrt(x * x + y * y);
    } while (a >= b + c || b >= a + c || c >= a + b);
}

//------------------------------------------------------------------------------
// Вывод параметров треугольника в поток
void Out(triangle& t, FILE* file) {
    fprintf(file, "It is Triangle. A-point: x = %d, y = %d. B-point: x = %d, y = %d. C-point: x = %d, y = %d. Perimeter = %f. Color: ",
        t.x_1, t.y_1, t.x_2, t.y_2, t.x_3, t.y_3, Perimeter(t));
}

//------------------------------------------------------------------------------
// Вычисление периметра треугольника
double Perimeter(triangle& t) {
    int x, y;
    x = std::abs(t.x_1 - t.x_2);
    y = std::abs(t.y_1 - t.y_2);
    double a = sqrt(x * x + y * y);

    x = std::abs(t.x_2 - t.x_3);
    y = std::abs(t.y_2 - t.y_3);
    double b = sqrt(x * x + y * y);

    x = std::abs(t.x_3 - t.x_1);
    y = std::abs(t.y_3 - t.y_1);
    double c = sqrt(x * x + y * y);
    return a + b + c;
}
