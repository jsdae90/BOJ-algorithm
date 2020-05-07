import sys
from math import gcd


def lcm(a, b):
    return a * b // gcd(a, b)


N = int(input())

for i in range(N):
    a, b = map(int, sys.stdin.readline().split())
    print(int(lcm(a, b)))
