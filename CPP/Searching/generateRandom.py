import random

with open('./searching.txt', 'w') as f:
    n = 100000
    f.write(str(n))
    f.write('\n')
    for i in range(0, n):
        f.write(str(random.randint(0, 10000000)))
        f.write(" ")
    f.close()