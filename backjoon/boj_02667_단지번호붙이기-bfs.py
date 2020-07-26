"""
boj_2667_단지번호붙이기(난이도 : 실버1)
bfs
"""

import sys
from collections import deque

N = int(sys.stdin.readline().rstrip())
arr = []

for n in range(N):
    line = sys.stdin.readline().rstrip()
    arr.append(list(line))

def bfs(arr, i, j, now, N):
    ni = [1,-1,0,0]
    nj = [0,0,1,-1]
    q = deque()
    q.append((i,j))
    cnt= 0
    while len(q):
        for i in range(len(q)):
            pos = q.popleft()
            if arr[pos[0]][pos[1]] == '1':
                arr[pos[0]][pos[1]] = str(now)
                cnt+=1
            else :
                continue
            for k in range(4):
                h = pos[0] + ni[k]
                w = pos[1] + nj[k]
                if h < 0 or h >= N or w < 0 or w >=N :
                    continue
                if arr[h][w] == '1':
                    q.append((h,w))
    return cnt

now = 2
rst = []
for i in range(N):
    for j in range(N):
        if arr[i][j] == '1':
            rst.append(bfs(arr,i,j,now, N))
            now+=1

rst.sort()
print(len(rst))
for i in rst:
    print(i)



