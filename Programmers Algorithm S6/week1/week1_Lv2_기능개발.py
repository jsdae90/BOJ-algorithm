import math


def solution(progresses, speeds):
    answer = []
    remain_day = []

    for i in range(len(progresses)):
        remain_day.append(math.ceil((100 - progresses[i]) / speeds[i]))

    for i in range(1, len(progresses)):
        if remain_day[i] <= remain_day[i - 1]:
            remain_day[i] = remain_day[i - 1]

    cnt = 1
    for i in range(1, len(remain_day)):
        if remain_day[i] == remain_day[i - 1]:
            cnt += 1
        else:
            answer.append(cnt)
            cnt = 1

    answer.append(cnt)

    return answer
