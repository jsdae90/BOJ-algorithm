from collections import deque


def solution(n, exec_times):
    queue = deque(exec_times)

    # finished_at: 서버가 처리 중인 일이 끝나는 시각
    # jobs_done: 서버가 처리한 코드 수
    servers = [{"finished_at": 0, "jobs_done": 0} for _ in range(n)]
    cur_time = 0

    while queue:
        for server in servers:
            if not queue:
                break
            if server["finished_at"] <= cur_time:
                server["finished_at"] += queue.popleft()
                server["jobs_done"] += 1
        cur_time += 1
    return [server["jobs_done"] for server in servers]

