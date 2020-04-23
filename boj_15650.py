import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())

N = [i for i in range(1, N + 1)]

comb = combinations(N, M)

for i in comb:
    print(" ".join(map(str, i)))
