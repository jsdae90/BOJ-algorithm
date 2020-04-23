import sys
from itertools import product

N, M = map(int, sys.stdin.readline().split())

N = [i for i in range(1, N + 1)]

prd = product(N, repeat=M)

for i in prd:
    print(" ".join(map(str, i)))
