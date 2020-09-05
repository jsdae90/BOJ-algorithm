def solution(s):
    stack = []

    for i in range(len(s)):
        if i == 0:
            stack.append(s[i])
        elif len(stack) == 0:
            stack.append(s[i])
        elif stack[-1] == s[i]:
            stack.pop()

    if stack:
        return 0
    else:
        return 1
