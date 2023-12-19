from matplotlib import pyplot as plt
import pandas as pd
from matplotlib.lines import Line2D

marks = [1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 25000, 50000, 100000]

sort = ["bubble", "shaker", "two way merge"]

with open("C:\\3rd_aisd_lab\\comparsions.txt", "r") as f:
    data = f.readlines()
    for num, line in enumerate(data):
        line = [int(x) for x in line.split()]
        line = pd.Series(line, index = marks)

        plt.figure()
        plt.plot(line.index, line.values)
        plt.title(f"Graph for {sort[num%3]} sort")
        plt.xlabel("Lenght of array")
        plt.ylabel("Comparsion count")
        plt.show()

with open("C:\\3rd_aisd_lab\\copies.txt", "r") as f:
    data = f.readlines()
    for num, line in enumerate(data):
        line = [int(x) for x in line.split()]
        line = pd.Series(line, index = marks)

        plt.figure()
        plt.plot(line.index, line.values)
        plt.title(f"Graph for {sort[num%3]} sort")
        plt.xlabel("Lenght of array")
        plt.ylabel("Copy count")
        plt.show()