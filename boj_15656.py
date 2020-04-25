import sys
from itertools import product

N, M = map(int, sys.stdin.readline().split())
data = sorted(list(map(int, sys.stdin.readline().split())))

prd = product(data, repeat=M)

for i in prd:
    print(" ".join(map(str, i)))
