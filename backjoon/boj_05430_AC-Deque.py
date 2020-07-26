"""
boj_5430_AC(난이도 : 실버2)
자료구조
1. Deque로 문제 그대로 구현해도 가능
2. 삽입이 없으므로 인덱스만 이동해도 가능
"""

from sys import stdin, stdout
from collections import deque

T = int(stdin.readline().rstrip())

def solve():
    q = deque()
    op = stdin.readline().rstrip()
    N = int(stdin.readline().rstrip())
    candidate = stdin.readline().rstrip().split(',')
    if N == 1:
        q.append(candidate[0][1:-1])
    elif N > 1:
        q.append(candidate[0][1:])
        for i in candidate[1:-1]:
            q.append(i)
        q.append(candidate[-1][:-1])

    dir = 0
    for i in op:
        if i == 'R':
           dir += 1
        else :
            if len(q)==0:
                return 'error\n'
            else :
                if dir % 2 == 0:
                    q.popleft()
                else :
                    q.pop()

    if len(q) == 0:
        return '[]\n'
    if dir % 2 == 1:
        q.reverse()
    return '[' + ','.join(q) + ']\n'

for t in range(T):
    stdout.write(solve())



