import random

with open('./maze.txt', 'w') as f:
    n = 10
    f.write(str(n))
    f.write('\n')
    for i in range(0, n):
        for j in range(0, n):
            f.write(str(random.randint(0, 1)))
            f.write(" ")
        f.write("\n")
    f.close()