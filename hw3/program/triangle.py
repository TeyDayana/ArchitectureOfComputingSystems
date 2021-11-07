import math
import color
import random
from shape import *
# ----------------------------------------------


class Triangle(Shape):
    def __init__(self):
        self.x_1 = int(0)
        self.y_1 = int(0)
        self.x_2 = 0
        self.y_2 = 0
        self.x_3 = 0
        self.y_3 = 0
        self.color = 0

    def get_figure(self, data, i):
        self.color = int(data[i])
        self.x_1 = int(data[i+1])
        self.y_1 = int(data[i+2])
        self.x_2 = int(data[i+3])
        self.y_2 = int(data[i+4])
        self.x_3 = int(data[i+5])
        self.y_3 = int(data[i+6])

    def get_random_figure(self):
        self.x_1 = random.randint(1, 21)
        self.y_1 = random.randint(1, 21)
        self.x_2 = random.randint(1, 21)
        self.y_2 = random.randint(1, 21)
        self.x_3 = random.randint(1, 21)
        self.y_3 = random.randint(1, 21)

        x = abs(self.x_1 - self.x_2)
        y = abs(self.y_1 - self.y_2)
        a = math.sqrt(x * x + y * y)

        x = abs(self.x_2 - self.x_3)
        y = abs(self.y_2 - self.y_3)
        b = math.sqrt(x * x + y * y)

        x = abs(self.x_3 - self.x_1)
        y = abs(self.y_3 - self.y_1)
        c = math.sqrt(x * x + y * y)

        while a >= b + c or b >= a + c or c >= a + b:
            self.x_1 = random.randint(1, 21)
            self.y_1 = random.randint(1, 21)
            self.x_2 = random.randint(1, 21)
            self.y_2 = random.randint(1, 21)
            self.x_3 = random.randint(1, 21)
            self.y_3 = random.randint(1, 21)

            x = abs(self.x_1 - self.x_2)
            y = abs(self.y_1 - self.y_2)
            a = math.sqrt(x * x + y * y)

            x = abs(self.x_2 - self.x_3)
            y = abs(self.y_2 - self.y_3)
            b = math.sqrt(x * x + y * y)

            x = abs(self.x_3 - self.x_1)
            y = abs(self.y_3 - self.y_1)
            c = math.sqrt(x * x + y * y)

    def perimeter(self):
        x = abs(self.x_1 - self.x_2)
        y = abs(self.y_1 - self.y_2)
        a = math.sqrt(x * x + y * y)

        x = abs(self.x_2 - self.x_3)
        y = abs(self.y_2 - self.y_3)
        b = math.sqrt(x * x + y * y)

        x = abs(self.x_3 - self.x_1)
        y = abs(self.y_3 - self.y_1)
        c = math.sqrt(x * x + y * y)
        return a + b + c

    def write(self, output):
        output.write("Triangle: x1 = {}  y1 = {}, x2 = {}  y2 = {}, "
                     "x3 = {}  y3 = {}. Perimeter = {}. Color is {}"
                     .format(self.x_1, self.y_1, self.x_2,
                             self.y_2, self.x_3, self.y_3,
                             self.perimeter(), color.get_color(self.color)))
