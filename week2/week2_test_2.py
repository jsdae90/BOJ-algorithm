def solution(s):
    stack = []
    open_bracket = {"(": 0, "{": 1, "[": 2}
    close_bracket = {")": 0, "}": 1, "]": 2}
    chr_idx = 0

    for chr in s:
        if chr in open_bracket:
            chr_idx = open_bracket[chr]
        elif chr in close_bracket:
            chr_idx = close_bracket[chr]
        if len(stack) == 0 and chr in close_bracket:
            return False
        elif chr in open_bracket:
            stack.append(chr_idx)
        else:
            if stack[-1] == close_bracket[chr]:
                stack.pop()
            else:
                stack.append(chr_idx)

    if len(stack) == 0:
        return True
    else:
        return False
