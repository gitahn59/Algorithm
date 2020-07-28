"""
boj_1389_케빈 베이컨의 6단계 법칙(난이도 : 실버1)
플로이드 와샬
"""

from sys import stdin, stdout

N, M = map(int,stdin.readline().rstrip().split(' '))
INF = 100000
arr = [[] for i in range(N)]
rst = [[INF for i in range(N)] for j in range(N)]
for i in range(N):
    rst[i][i] = 0
for m in range(M):
    i, j = map(int, stdin.readline().rstrip().split(' '))
    arr[i-1].append(j-1)
    rst[i-1][j-1] = 1
    arr[j-1].append(i-1)
    rst[j-1][i-1] = 1

def floyd_warshall(arr, rst, N):
    for k in range(N): # k를 거쳐갈 때
        for i in range(N):
            for j in range(N):
                if rst[i][j] > rst[i][k] + rst[k][j]:
                    rst[i][j] = rst[i][k] + rst[k][j]

floyd_warshall(arr,rst,N)

idx = 0
now = sum(rst[0])
for i in range(1,N):
    num = sum(rst[i])
    if num < now:
        now = num
        idx = i
    
stdout.write(str(idx+1)+'\n')






