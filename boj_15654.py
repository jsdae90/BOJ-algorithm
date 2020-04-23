import sys
from itertools import permutations

n, m = map(int, sys.stdin.readline().split())
data = sorted(list(map(int, sys.stdin.readline().split())))

per = permutations(data, m)

for i in per:
    print(" ".join(map(str, i)))
