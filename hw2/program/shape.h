#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"

//------------------------------------------------------------------------------
// класс, обобщающий все имеющиеся фигуры
class Shape {
protected:
    static Random rnd20;
    static Random rnd3;
    static Random rnd7;
//    enum color { RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE, NONE };
//    color col;
    int color;

public:
    virtual ~Shape() {};
    // Ввод обобщенной фигуры
    static Shape *StaticIn(FILE *file, int k);
    virtual void In(FILE *file) = 0;
    // Случайный ввод обобщенной фигуры
    static Shape *StaticInRnd();
    virtual void InRnd() = 0;
    // Вывод обобщенной фигуры
    virtual void Out(FILE *file) = 0;
    // Вычисление периметра обобщенной фигуры
    virtual double Perimeter() = 0;

    // Получение типа цвета по числу
    //Shape::color Color(int n);
    // Запись цвета в файл
    //void ColorPrint(Shape::color color, FILE* file);
};

//struct shape {
//    // значения ключей для каждой из фигур
//    enum key { RECTANGLE, TRIANGLE, CIRCLE };
//    enum color { RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PURPLE, NONE };
//    key k; // ключи
//    color col;
//};
//

#endif