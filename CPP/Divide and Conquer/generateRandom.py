import random

with open('./dnc.txt', 'w') as f:
    n = 1000
    f.write(str(n))
    f.write('\n')
    for i in range(0, n):
        f.write(str(random.randint(0, 10000000)))
        f.write(" ")
    f.close()