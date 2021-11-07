import math
import color
import random
from shape import *
# ----------------------------------------------


class Circle(Shape):
    def __init__(self):
        self.x_c = 0
        self.y_c = 0
        self.r = 0
        self.color = 0

    def get_figure(self, data, i):
        self.color = int(data[i])
        self.x_c = int(data[i+1])
        self.y_c = int(data[i+2])
        self.r = int(data[i+3])

    def get_random_figure(self):
        self.x_c = random.randint(1, 21)
        self.y_c = random.randint(1, 21)
        self.r = random.randint(1, 21)

    def perimeter(self):
        return 2.0 * math.pi * float(self.r)

    def write(self, output):
        output.write("Circle: (center) x = {}  y = {}, r = {}. "
                     "Perimeter = {}. Color is {}"
                     .format(self.x_c, self.y_c, self.r,
                             self.perimeter(), color.get_color(self.color)))
