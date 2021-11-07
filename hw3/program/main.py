# ----------------------------------------------
import sys
from container import *


def error():
    print("Incorrect command line!\nYou must write: "
          "[python main] -f <inputFileName> <outputFileName> <outputSortedFileName>\n"
          "Or: [python main] -n <numberOfFigures> <outputSortedFileName>")
    exit()


if __name__ == '__main__':
    if len(sys.argv) != 5:
        error()

    print('==> Start')
    container = Container()

    if sys.argv[1] == "-f":
        inputFile = open(sys.argv[2])
        data = inputFile.read().replace("\n", " ").split(" ")
        container.get_figures(data)
        inputFile.close()
    elif sys.argv[1] == "-n":
        size = int(sys.argv[2])
        if size < 1 or size > 10000:
            print("Incorrect number of figures. Set between 0 and 10000")
            exit()
        container.get_random_figures(size)
    else:
        error()

    outputFile = open(sys.argv[3], "w+")
    container.write(outputFile)
    outputFile.close()

    outputFile = open(sys.argv[4], "w+")
    container.sort(outputFile)
    outputFile.close()
    print('==> Finish')
