#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key { RECTANGLE, TRIANGLE, CIRCLE };
    enum color { RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE, NONE };
    key k; // ключи
    color col;
    // используемые альтернативы
    union { // используем простейшую реализацию
        rectangle r;
        triangle t;
        circle c;
    };
};

// Ввод обобщенной фигуры
shape* In(FILE *file, int k);

// Получение типа цвета по числу
shape::color Color(int n);

// Случайный ввод обобщенной фигуры
shape* InRnd();

// Вывод обобщенной фигуры
void Out(shape& s, FILE* file);

// Запись цвета в файл
void ColorPrint(shape::color color, FILE* file);

// Вычисление периметра обобщенной фигуры
double Perimeter(shape& s);

#endif
