"""
boj_1697_숨바꼭질(난이도 : 실버1)
bfs
bfs를 통해 조건의 이동에 따라 계산할수 있는 최단 횟수 계산
"""

import sys
import collections

N, K = sys.stdin.readline().rstrip().split(' ')
N = int(N)
K = int(K)

def bfs(n,k):
    if n==k:
        return 0

    arr = [-1 for i in range(200010)]
    q = collections.deque()
    q.append(n)
    arr[n] = 0
    K = k*2
    t=0
    while len(q):
        qs = len(q)
        t+=1
        for i in range(qs):
            now = q.popleft()
            if now+1<=K and arr[now+1] == -1:
                arr[now+1] = t
                q.append(now+1)
                if now+1==k:
                    return t
            if now-1>=0 and arr[now-1] == -1:
                arr[now-1] = t
                q.append(now-1)
                if now-1==k:
                    return t
            if now*2 <= K and arr[now*2] == -1:
                arr[now*2] = t
                q.append(now*2)
                if now*2==k:
                    return t

print(bfs(N,K))





