def solution(progresses, speeds):
    answer = []
    days = len(progresses) * [0]

    for idx in range(len(progresses)):
        while progresses[idx] < 100:
            days[idx] += 1
            progresses[idx] += speeds[idx]

    for idx in range(1, len(days)):
        if days[idx] < days[idx - 1]:
            days[idx] = days[idx - 1]

    for day in sorted(set(days)):
        answer.append(days.count(day))

    return answer
