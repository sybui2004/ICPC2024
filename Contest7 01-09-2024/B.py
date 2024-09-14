import math

def binomial(n, k):
    return math.comb(n, k)

MAX_N = 50
a = [0] * (MAX_N + 1)
a[0] = 1
a[1] = 1

for n in range(2, MAX_N + 1):
    for k in range(n):
        a[n] += a[k] * binomial(n-1, k)

for i in range(int(input())):
    print(a[int(input())])