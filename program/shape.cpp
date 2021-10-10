//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "shape.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
shape* In(FILE *file, int k) {
    shape* sp;
    int color;
    fscanf(file, "%d", &color);
    switch (k) {
    case 1:
        sp = new shape;
        sp->k = shape::RECTANGLE;
        sp->col = Color(color);
        In(sp->r, file);
        return sp;
    case 2:
        sp = new shape;
        sp->k = shape::TRIANGLE;
        sp->col = Color(color);
        In(sp->t, file);
        return sp;
    case 3:
        sp = new shape;
        sp->k = shape::CIRCLE;
        sp->col = Color(color);
        In(sp->c, file);
        return sp;
    default:
        return 0;
    }
}

// Получение типа цвета по числу
shape::color Color(int n) {
    switch (n) {
    case 1:
        return shape::RED;
    case 2:
        return shape::ORANGE;
    case 3:
        return shape::YELLOW;
    case 4:
        return shape::GREEN;
    case 5:
        return shape::CYAN;
    case 6:
        return shape::BLUE;
    case 7:
        return shape::PURPLE;
    default:
        return shape::NONE;
    }
}

// Случайный ввод обобщенной фигуры
shape* InRnd() {
    shape* sp;
    auto k = rand() % 3 + 1;
    auto color = rand() % 7 + 1;
    switch (k) {
    case 1:
        sp = new shape;
        sp->k = shape::RECTANGLE;
        sp->col = Color(color);
        InRnd(sp->r);
        return sp;
    case 2:
        sp = new shape;
        sp->k = shape::TRIANGLE;
        sp->col = Color(color);
        InRnd(sp->t);
        return sp;
    case 3:
        sp = new shape;
        sp->k = shape::CIRCLE;
        sp->col = Color(color);
        InRnd(sp->c);
        return sp;
    default:
        return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в поток
void Out(shape& s, FILE *file) {
    switch (s.k) {
    case shape::RECTANGLE:
        Out(s.r, file);
        break;
    case shape::TRIANGLE:
        Out(s.t, file);
        break;
    case shape::CIRCLE:
        Out(s.c, file);
        break;
    default:
       fprintf(file, "Incorrect figure!");
       return;
    }
    ColorPrint(s.col, file);
}

// Запись цвета в файл
void ColorPrint(shape::color color, FILE *file) {
    switch (color) {
    case shape::RED:
        fprintf(file, "red\n");
        break;
    case shape::ORANGE:
        fprintf(file, "orange\n");
        break;
    case shape::YELLOW:
        fprintf(file, "yellow\n");
        break;
    case shape::GREEN:
        fprintf(file, "green\n");
        break;
    case shape::CYAN:
        fprintf(file, "cyan\n");
        break;
    case shape::BLUE:
        fprintf(file, "blue\n");
        break;
    case shape::PURPLE:
        fprintf(file, "purple\n");
        break;
    case shape::NONE:
        fprintf(file, "cannot identify\n");
        break;
    default:
        break;
    }
}

//------------------------------------------------------------------------------
// Вычисление периметра фигуры
double Perimeter(shape& s) {
    switch (s.k) {
    case shape::RECTANGLE:
        return Perimeter(s.r);
        break;
    case shape::TRIANGLE:
        return Perimeter(s.t);
        break;
    case shape::CIRCLE:
        return Perimeter(s.c);
        break;
    default:
        return 0.0;
    }
}
