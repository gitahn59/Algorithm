"""
boj_10866_덱(난이도 : 실버4)
자료구조
"""

import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())

q = deque([])
for n in range(N):
    op = sys.stdin.readline().rstrip().split(' ')
    if op[0] == 'push_back':
        q.append(op[1])
    elif op[0] == 'push_front':
        q.appendleft(op[1])
    elif op[0] == 'pop_back':
        if len(q) == 0:
            print(-1)
        else:
            print(q.pop())
    elif op[0] == 'pop_front':
        if len(q) == 0:
            print(-1)
        else:
            print(q.popleft())
    elif op[0] == 'size':
        print(len(q))
    elif op[0] == 'empty':
        if len(q) == 0 :
            print(1)
        else:
            print(0)
    elif op[0] == 'front':
        if len(q) == 0:
            print(-1)
        else:
            print(q[0])
    elif op[0] == 'back':
        if len(q) == 0:
            print(-1)
        else:
            print(q[-1])






