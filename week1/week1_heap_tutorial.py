from collections import deque
import heapq


def solution(n, exec_times):
    queue = deque(exec_times)

    FINISHED_AT, SERVER_ID, JOBS_DONE = 0, 1, 2
    servers = [[0, i, 0] for i in range(n)]
    heapq.heapify(servers)

    while queue:
        target_server = heapq.heappop(servers)
        target_server[FINISHED_AT] += queue.popleft()
        target_server[JOBS_DONE] += 1
        heapq.heappush(servers, target_server)

    servers.sort(key=lambda x: x[SERVER_ID])
    return [server[JOBS_DONE] for server in servers]
