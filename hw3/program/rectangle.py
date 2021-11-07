import color
import random
from shape import *
# ----------------------------------------------


class Rectangle(Shape):
    def __init__(self):
        self.x_l_t = 0
        self.y_l_t = 0
        self.x_r_b = 0
        self.y_r_b = 0
        self.color = 0

    def get_figure(self, data, i):
        self.color = int(data[i])
        self.x_l_t = int(data[i+1])
        self.y_l_t = int(data[i+2])
        self.x_r_b = int(data[i+3])
        self.y_r_b = int(data[i+4])

    def get_random_figure(self):
        self.x_l_t = random.randint(0, 21)
        self.y_l_t = random.randint(0, 21)
        self.x_r_b = random.randint(0, 21)
        while self.x_r_b == self.x_l_t:
            self.x_r_b = random.randint(0, 21)
        self.y_r_b = random.randint(0, 21)
        while self.y_r_b == self.y_l_t:
            self.y_r_b = random.randint(0, 21)

    def perimeter(self):
        x = abs(self.x_l_t - self.x_r_b)
        y = abs(self.y_l_t - self.y_r_b)
        return 2.0 * (x + y)

    def write(self, output):
        output.write("Rectangle: x (top left) = {}  y (top left) = {}, "
                     "x (bottom right) = {}  y (bottom right) = {}. "
                     "Perimeter = {}. Color is {}"
                     .format(self.x_l_t, self.y_l_t, self.x_r_b, self.y_r_b,
                             self.perimeter(), color.get_color(self.color)))
