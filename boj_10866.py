import sys
from collections import deque


class bojDeQue:
    def __init__(self):
        self.deque = deque()
        self.len = 0

    def push_front(self, x):
        self.deque.appendleft(x)
        self.len += 1

    def push_back(self, x):
        self.deque.append(x)
        self.len += 1

    def pop_front(self):
        if self.len == 0:
            return -1
        else:
            self.len -= 1
            return self.deque.popleft()

    def pop_back(self):
        if self.len == 0:
            return -1
        else:
            self.len -= 1
            return self.deque.pop()

    def size(self):
        return self.len

    def empty(self):
        if self.len == 0:
            return 1
        else:
            return 0

    def front(self):
        if self.len == 0:
            return -1
        else:
            return self.deque[0]

    def back(self):
        if self.len == 0:
            return -1
        else:
            return self.deque[-1]


n = int(input())
deQ = bojDeQue()

while n > 0:
    n -= 1
    order = list(sys.stdin.readline().split())
    if order[0] == "push_front":
        deQ.push_front(order[1])
    elif order[0] == "push_back":
        deQ.push_back(order[1])
    elif order[0] == "pop_front":
        print(deQ.pop_front())
    elif order[0] == "pop_back":
        print(deQ.pop_back())
    elif order[0] == "size":
        print(deQ.size())
    elif order[0] == "empty":
        print(deQ.empty())
    elif order[0] == "front":
        print(deQ.front())
    elif order[0] == "back":
        print(deQ.back())
