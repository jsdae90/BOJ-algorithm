data = list(input())
ans = 0
stk = []

for i in range(len(data)):
    if data[i] == "(":
        stk.append("(")
    else:
        if data[i - 1] == "(":
            stk.pop()
            ans += len(stk)
        else:
            stk.pop()
            ans += 1

print(ans)
