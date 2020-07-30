"""
boj_1966_프린터 큐(난이도 : 실버 3)
deque
deque를 사용해 프린터 큐를 시뮬레이션 하고
탐색 속도를 위해 우선순위의 리스트를 정렬하여
현재 우선순위 확인은 O(1)에 탐색함
따라서 큐를 돌리는데 N^2이 걸리므로
O(N^2) 풀이가 가능함
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations
from collections import deque

T = int(stdin.readline().rstrip())

test = list()

for t in range(T):
    N, M = map(int, stdin.readline().rstrip().split(' '))
    line = map(int, stdin.readline().rstrip().split(' '))
    arr = deque()
    candidate = []
    for i in enumerate(line) :
        arr.append(i)
        candidate.append(i[1])
    candidate.sort()
    candidate.reverse()
    
    for idx, num in enumerate(candidate):
        flag = False
        while True:
            i = arr.popleft()
            if num == i[1]: # 우선순위 같으면
                if M == i[0]:
                    flag = True
                break
            else :
                arr.append(i)
        if flag :
            stdout.write(str(idx+1)+'\n')
            break;



