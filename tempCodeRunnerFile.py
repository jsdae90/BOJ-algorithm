import sys
import queue

n = 7
k = 3

QQ = [i for i in range(1, n+1)]
answer = []
tmp = k-1

while True :
    answer.append(QQ.pop(tmp))
    if not QQ :
        break
    tmp = (tmp+k-1) % len(QQ)

print('<'+', '.join(map(str, answer))+'>')