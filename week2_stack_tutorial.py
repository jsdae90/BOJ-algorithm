def solution(sentence):
    stack = []
    for chr in sentence:
        while stack and stack[-1] == chr:
            stack.pop()
        stack.append(chr)
    return "".join(stack)

