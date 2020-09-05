import heapq


def solution(N, works):
    if N > sum(works):
        return 0
    works = [(-i, i) for i in works]
    heapq.heapify(works)
    for _ in range(N):
        w = heapq.heappop(works)[1] - 1
        heapq.heappush(works, (-w, w))
    return sum([i[1] ** 2 for i in works])
