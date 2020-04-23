from itertools import permutations
import sys

N, M = map(int, sys.stdin.readline().split())
inp = []

for i in range(1, N + 1):
    inp.append(i)

per = permutations(inp, M)

for i in per:
    print(" ".join(map(str, i)))

