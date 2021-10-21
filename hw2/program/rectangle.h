#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание прямоугольника  и его интерфейса
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// прямоугольник
class Rectangle: public Shape {
public:
    virtual ~Rectangle() {}
    // Ввод параметров прямоугольника из файла
    virtual void In(FILE *file);
    // Случайный ввод параметров прямоугольника
    virtual void InRnd();
    // Вывод параметров прямоугольника в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление периметра прямоугольника
    virtual double Perimeter();

private:
    int x_l_t, y_l_t; // координаты левого верхнего угла
    int x_r_b, y_r_b; // координаты правого нижнего угла
};

#endif //__rectangle__