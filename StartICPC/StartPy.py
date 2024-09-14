import math

def isPrime(n):
    if n == 2 or n == 3: return True
    if n % 2 == 0 or n == 1: return False
    for i in range(5, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True
