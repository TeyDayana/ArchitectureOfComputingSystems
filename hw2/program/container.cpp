//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "container.h"

//------------------------------------------------------------------------------
// Конструктор контейнера
Container::Container(): len{0} { }

//------------------------------------------------------------------------------
// Деструктор контейнера
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void Container::In(FILE *file) {
    int k;
    while (fscanf(file, "%d", &k) != EOF) {
        if ((storage[len] = Shape::StaticIn(file, k)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Shape::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//----------------------------  --------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i+1);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Вывод обработки данных контейнера
void Container::ProcessingVar23(FILE* file) {
    double sum = 0.0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->Perimeter();
    }
    double mean = sum / len;
    fprintf(file, "Arithmetic mean: %f\n", mean);

    fprintf(file, "Perimeteres processed:\n");
    for (int i = 0; i < len; i++) {
        if (storage[i]->Perimeter() > mean) {
            fprintf(file, "%f   ", storage[i]->Perimeter());
        }
    }

    for (int i = 0; i < len; i++) {
        if (storage[i]->Perimeter() <= mean) {
            fprintf(file, "%f   ", storage[i]->Perimeter());
        }
    }
}