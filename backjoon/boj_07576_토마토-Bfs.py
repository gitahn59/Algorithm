"""
boj_7576_토마토(난이도 : 실버1)
기본적인 bfs
"""

import sys
from collections import deque

W, H = map(int,str(sys.stdin.readline().rstrip()).split(' '))

q = deque()
arr = []
for h in range(H):
    line = str(sys.stdin.readline().rstrip()).split(' ')
    temp = []
    for w in range(W):
        temp.append(int(line[w]))
        if line[w] == '1':
            q.append((h,w))
    arr.append(temp)

def bfs(arr, h , w, q):
    nh = [1,-1,0,0]
    nw = [0,0,1,-1]

    if len(q) == 0:
        return 0

    time=-1
    while len(q) !=0:
        qsize = len(q)
        time+=1
        for i in range(qsize):
            now = q.popleft()
            for k in range(4):
                i = now[0] + nh[k]
                j = now[1] + nw[k]
                if i<0 or i>=H or j<0 or j>=W:
                    continue

                if arr[i][j] == 0:
                    arr[i][j] = 1
                    q.append((i,j))
                else:
                    continue
    
    for h in range(H):
        for w in range(W):
            if arr[h][w] == 0:
                return -1

    return time

print(bfs(arr,H,W,q))



