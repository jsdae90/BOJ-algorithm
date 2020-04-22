import sys

n = int(sys.stdin.readline())
QQ = []
for i in range(n):
    ord = sys.stdin.readline().split()
    if ord[0] == "push":
        QQ.append(ord[1])
    if ord[0] == "pop":
        if QQ:
            print(QQ.pop(0))
        else:
            print(-1)
    if ord[0] == "size":
        print(len(QQ))
    if ord[0] == "empty":
        if QQ:
            print(0)
        else:
            print(1)
    if ord[0] == "front":
        if QQ:
            print(QQ[0])
        else:
            print(-1)
    if ord[0] == "back":
        if QQ:
            print(QQ[-1])
        else:
            print(-1)
