#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - содержит описание круга
//------------------------------------------------------------------------------

#include "stdio.h"
#include "random.h"
#include "shape.h"

// круг
class Circle: public Shape {
public:
    virtual ~Circle() {}
    // Ввод параметров треугольника из файла
    virtual void In(FILE* file);
    // Случайный ввод параметров треугольника
    virtual void InRnd();
    // Вывод параметров треугольника в форматируемый поток
    virtual void Out(FILE* file);
    // Вычисление периметра треугольника
    virtual double Perimeter();

private:
    int x_c, y_c; // координаты центра
    int r; // радиус
};

#endif //__circle__