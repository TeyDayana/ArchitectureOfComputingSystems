from rectangle import *
from triangle import *
from circle import *
# ----------------------------------------------


class Container:
    def __init__(self):
        self.store = []

    def get_figures(self, data):
        i = 0
        shape = 0
        while i < len(data):
            fig = int(data[i])
            if fig == 1:
                shape = Rectangle()
                shape.get_figure(data, i+1)
                i += 4
            elif fig == 2:
                shape = Triangle()
                shape.get_figure(data, i+1)
                i += 6
            elif fig == 3:
                shape = Circle()
                shape.get_figure(data, i+1)
                i += 3
            i += 2
            self.store.append(shape)

    def get_random_figures(self, count):
        i = 0
        shape = 0
        while i < count:
            fig = random.randint(1, 4)
            if fig == 1:
                shape = Rectangle()
                shape.get_random_figure()
                shape.color = random.randint(1, 8)
            if fig == 2:
                shape = Triangle()
                shape.get_random_figure()
                shape.color = random.randint(1, 8)
            if fig == 3:
                shape = Circle()
                shape.get_random_figure()
                shape.color = random.randint(1, 8)
            i += 1
            self.store.append(shape)

    def write(self, output):
        output.write("Container is store {} shapes:\n"
                     .format(len(self.store)))
        for shape in self.store:
            shape.write(output)
            output.write("\n")

    def sort(self, output):
        s = 0.0
        for shape in self.store:
            s += shape.perimeter()
        mean = s / len(self.store)
        output.write("Sorted container:\n\n")
        for shape in self.store:
            if shape.perimeter() > mean:
                shape.write(output)
                output.write("\n")
        output.write("\n")
        for shape in self.store:
            if shape.perimeter() <= mean:
                shape.write(output)
                output.write("\n")
