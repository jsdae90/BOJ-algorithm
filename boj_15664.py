import sys
from itertools import combinations

N, M = map(int, sys.stdin.readline().split())
data = sorted(list(map(int, sys.stdin.readline().split())))

comb = combinations(data, M)

comb = sorted(list(set(comb)))

for i in comb:
    print(" ".join(map(str, i)))
