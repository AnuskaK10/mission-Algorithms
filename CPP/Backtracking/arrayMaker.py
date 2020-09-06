import random

with open('./array.txt', 'w') as f:
    n = 10
    f.write(str(n))
    f.write('\n')
    for i in range(0, n):
        f.write(str(random.randint(-n/2, n)))
        f.write(" ")
    f.write("\n")
    f.write(str(random.randint(-n, n)))
    f.close()