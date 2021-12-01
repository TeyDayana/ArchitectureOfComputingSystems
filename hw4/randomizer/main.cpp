#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include "stdio.h"

FILE *file_;
void writeRectangleData();
void writeTriangleData();
void writeCircleData();
int getRandomNumber(int min, int max);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("first argument must be the number of figures or 'r' - random number, and the second must be full path of file to write the result in");
        return 1;
    }

    int size;
    srand(static_cast<unsigned int>(time(0)));
    if (!strcmp(argv[1], "r")) {
        size = getRandomNumber(1, 10000);
    } else {
        size = atoi(argv[1]);
        if (size < 1 || size > 10000) {
            printf("number of figures must be positive and no more than 10000");
            return 2;
        }
    }
    file_ = fopen(argv[2], "w");

    int figure;
    for (int fig = 0; fig < size; ++fig) {
        figure = getRandomNumber(1, 3);
        fprintf(file_, "%d %d ", figure, getRandomNumber(1, 7));
        switch (figure) {
            case 1:
                writeRectangleData();
                break;
            case 2:
                writeTriangleData();
                break;
            case 3:
                writeCircleData();
                break;
        }
    }

    return 0;
}

void writeRectangleData() {
    int x_l_t, y_l_t, x_r_b, y_r_b;
    x_l_t = getRandomNumber(-20, 20);
    y_l_t = getRandomNumber(-20, 20);

    do {
        x_r_b = getRandomNumber(-20, 20);
    } while (x_r_b == y_l_t);

    do {
        y_r_b = getRandomNumber(-20, 20);
    } while (y_r_b == y_l_t);
    fprintf(file_, "%d %d %d %d ", x_l_t, y_l_t, x_r_b, y_r_b);
}

void writeTriangleData() {
    int x_1, y_1, x_2, y_2, x_3, y_3;
    double a, b, c, x, y;
    do {
        x_1 = getRandomNumber(-20, 20);
        y_1 = getRandomNumber(-20, 20);
        x_2 = getRandomNumber(-20, 20);
        y_2 = getRandomNumber(-20, 20);
        x_3 = getRandomNumber(-20, 20);
        y_3 = getRandomNumber(-20, 20);

        x = std::abs(x_1 - x_2);
        y = std::abs(y_1 - y_2);
        a = sqrt(x * x + y * y);

        x = std::abs(x_2 - x_3);
        y = std::abs(y_2 - y_3);
        b = sqrt(x * x + y * y);

        x = std::abs(x_3 - x_1);
        y = std::abs(y_3 - y_1);
        c = sqrt(x * x + y * y);
    } while (a >= b + c || b >= a + c || c >= a + b);
    fprintf(file_, "%d %d %d %d %d %d ", x_1, y_1, x_2, y_2, x_3, y_3);
}

void writeCircleData() {
    int x_c, y_c, r;
    x_c = getRandomNumber(-20, 20);
    y_c = getRandomNumber(-20, 20);
    r = getRandomNumber(1, 50);
    fprintf(file_, "%d %d %d ", x_c, y_c, r);
}

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
