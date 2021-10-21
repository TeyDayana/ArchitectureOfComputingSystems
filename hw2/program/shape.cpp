//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "rectangle.h"
#include "triangle.h"
#include "circle.h"
//------------------------------------------------------------------------------
Random Shape::rnd20(1, 20);
Random Shape::rnd3(1, 3);
Random Shape::rnd7(1, 7);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
Shape *Shape::StaticIn(FILE *file, int k) {
    Shape* sp = nullptr;
    int color;
    fscanf(file, "%d", &color);

    switch(k) {
        case 1:
            sp = new Rectangle;
            sp->color = color;
            break;
        case 2:
            sp = new Triangle;
            sp->color = color;
            break;
        case 3:
            sp = new Circle;
            sp->color = color;
            break;
        default:
            return 0;
    }
    sp->In(file);
    return sp;
}

// Случайный ввод обобщенной фигуры
Shape *Shape::StaticInRnd() {
    auto k = Shape::rnd3.Get();
    auto color = Shape::rnd7.Get();
    Shape* sp = nullptr;
    switch(k) {
        case 1:
            sp = new Rectangle;
            sp->color = color;
        case 2:
            sp = new Triangle;
            sp->color = color;
        case 3:
            sp = new Circle;
            sp->color = color;
    }
    sp->InRnd();
    return sp;
}

//// Получение типа цвета по числу
//shape::color Color(int n) {
//    switch (n) {
//        case 1:
//            return shape::RED;
//        case 2:
//            return shape::ORANGE;
//        case 3:
//            return shape::YELLOW;
//        case 4:
//            return shape::GREEN;
//        case 5:
//            return shape::CYAN;
//        case 6:
//            return shape::BLUE;
//        case 7:
//            return shape::PURPLE;
//        default:
//            return shape::NONE;
//    }
//}
//
////------------------------------------------------------------------------------
//// Вывод параметров текущей фигуры в поток
//void Out(shape& s, FILE *file) {
//    switch (s.k) {
//        case shape::RECTANGLE:
//            Out(s.r, file);
//            break;
//        case shape::TRIANGLE:
//            Out(s.t, file);
//            break;
//        case shape::CIRCLE:
//            Out(s.c, file);
//            break;
//        default:
//            fprintf(file, "Incorrect figure!");
//            return;
//    }
//    ColorPrint(s.col, file);
//}
//
//// Запись цвета в файл
//void ColorPrint(shape::color color, FILE *file) {
//    switch (color) {
//        case shape::RED:
//            fprintf(file, "red\n");
//            break;
//        case shape::ORANGE:
//            fprintf(file, "orange\n");
//            break;
//        case shape::YELLOW:
//            fprintf(file, "yellow\n");
//            break;
//        case shape::GREEN:
//            fprintf(file, "green\n");
//            break;
//        case shape::CYAN:
//            fprintf(file, "cyan\n");
//            break;
//        case shape::BLUE:
//            fprintf(file, "blue\n");
//            break;
//        case shape::PURPLE:
//            fprintf(file, "purple\n");
//            break;
//        case shape::NONE:
//            fprintf(file, "cannot identify\n");
//            break;
//        default:
//            break;
//    }
//}
//
////------------------------------------------------------------------------------
//// Вычисление периметра фигуры
//double Perimeter(shape& s) {
//    switch (s.k) {
//        case shape::RECTANGLE:
//            return Perimeter(s.r);
//            break;
//        case shape::TRIANGLE:
//            return Perimeter(s.t);
//            break;
//        case shape::CIRCLE:
//            return Perimeter(s.c);
//            break;
//        default:
//            return 0.0;
//    }
//}