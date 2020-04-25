import sys
from itertools import permutations

N, M = map(int, sys.stdin.readline().split())
data = list(map(int, sys.stdin.readline().split()))

per = permutations(data, M)

per = sorted(list(set(per)))

for i in per:
    print(" ".join(map(str, i)))
