import sys
from itertools import combinations_with_replacement

N, M = map(int, sys.stdin.readline().split())
data = sorted(list(map(int, sys.stdin.readline().split())))

cwr = combinations_with_replacement(data, M)

for i in cwr:
    print(" ".join(map(str, i)))
