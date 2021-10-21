#ifndef __random__
#define __random__

#include <cstdlib>
#include <ctime>   // для функции time()

//------------------------------------------------------------------------------
// random.h - содержит генератор случайных чисел в диапазоне от 1 до 20
//------------------------------------------------------------------------------

class Random {
public:
    Random(int fst, int lst) {
        if(fst <= lst) {
            first = fst;
            last = lst;
        } else {
            first = lst;
            last = fst;
        }
        // системные часы в качестве инициализатора
        srand(static_cast<unsigned int>(time(0)));
    }

    // Генерация случайного числа в заданном диапазоне
    int Get() {
        return rand() % (last - first + 1) + first;
    }

private:
    int first;
    int last;
};

#endif //__random__