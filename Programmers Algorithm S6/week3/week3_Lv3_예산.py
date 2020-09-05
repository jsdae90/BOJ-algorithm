def solution(budgets, M):
    left, right = 0, max(budgets)
    answer = 0
    while left <= right:
        mid = (left + right) // 2
        temp = [i if i < mid else mid for i in budgets]
        if sum(temp) > M:
            right = mid - 1
        elif sum(temp) <= M:
            answer = mid
            left = mid + 1
    return answer
