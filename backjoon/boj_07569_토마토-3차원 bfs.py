"""
boj_7569_토마토(난이도 : 실버1)
3차원 matrix bfs
일반 적인 그래프 traversal에 한 차원만 더 추가해주면 됨
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations
from collections import deque  

M, N, H = map(int,stdin.readline().rstrip().split(' '))
arr = []
q = deque()

for h in range(H):
    square = []
    for n in range(N):
        line = stdin.readline().rstrip().split(' ')
        square.append(line)
        for m in range(M):
            if line[m] == '1':
                q.append((h,n,m))
    arr.append(square)

move = ((0,0,1),(0,0,-1),(0,1,0),(0,-1,0),(1,0,0),(-1,0,0))

# bfs
def bfs(arr, q, H, N, M):
    t = 0
    while len(q):
        t += 1
        for _ in range(len(q)):
            h, n, m = q.popleft()
            for i,j,k in move:
                nh = h + i
                nn = n + j
                nm = m + k
                if nh < 0 or nh==H or nn <0 or nn == N or nm < 0 or nm == M:
                    continue
                if arr[nh][nn][nm] == '0':
                    arr[nh][nn][nm] = '1'
                    q.append((nh,nn,nm))

    for square in arr:
        for line in square:
            for i in line:
                if i == '0':
                    return '-1\n'

    return str(t-1) + '\n'

stdout.write(bfs(arr,q,H,N,M))




