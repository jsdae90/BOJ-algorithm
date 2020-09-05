from itertools import combinations


def prime(n):
    check_prime = [True] * n
    sqrt_n = int(n ** 0.5)
    for i in range(2, sqrt_n + 1):
        if check_prime[i] == True:
            for j in range(i + i, n, i):
                check_prime[j] = False
    return [i for i in range(2, n) if check_prime[i] == True]


def solution(n):
    answer = 0
    prime_num = prime(n)
    comb_prime = combinations(prime_num, 3)

    for comb in comb_prime:
        if sum(comb) == int(n):
            answer += 1

    return answer
