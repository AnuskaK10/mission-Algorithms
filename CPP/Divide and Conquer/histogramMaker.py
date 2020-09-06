import random

with open('./histogram.txt', 'w') as f:
    n = 10
    f.write(str(n))
    f.write('\n')
    for i in range(0, n):
        f.write(str(random.randint(1, n)))
        f.write(" ")
    f.write("\n")
    f.close()