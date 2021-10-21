#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание треугольника
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// треугольник
class Triangle: public Shape {
public:
    virtual ~Triangle() {}
    // Ввод параметров треугольника из файла
    virtual void In(FILE *file);
    // Случайный ввод параметров треугольника
    virtual void InRnd();
    // Вывод параметров треугольника в форматируемый поток
    virtual void Out(FILE *file);
    // Вычисление периметра треугольника
    virtual double Perimeter();

private:
    int x_1, y_1; // координаты 1го угла
    int x_2, y_2; // координаты 2го угла
    int x_3, y_3; // координаты 3го угла
};

#endif //__triangle__