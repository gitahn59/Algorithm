"""
boj_11403_경로 찾기(난이도 : 실버1)
플로이드 와샬 알고리즘
플로이드 와샬 3중 포문 구조로
첫번째 루프는 거쳐갈 경로
2,3번째 루프는 시작, 종료 노드를 담당함

def floyd_warshall(arr, rst, N):
    for k in range(N): # k를 거쳐갈 때
        for i in range(N):
            for j in range(N):
                if rst[i][j] > rst[i][k] + rst[k][j]:
                    rst[i][j] = rst[i][k] + rst[k][j]
"""

from sys import stdin, stdout

N = int(stdin.readline().rstrip())
INF = 100000
arr = [[] for i in range(N)]
rst = [[INF for i in range(N)] for j in range(N)]

for i in range(N):
    line = list(map(int, stdin.readline().rstrip().split(' ')))
    for j in range(N):
        if line[j] == 1:
            arr[i].append(j)
            rst[i][j] = 1

def floyd_warshall(arr, rst, N):
    for k in range(N): # k를 거쳐갈 때
        for i in range(N):
            for j in range(N):
                if rst[i][j] > rst[i][k] + rst[k][j]:
                    rst[i][j] = rst[i][k] + rst[k][j]

floyd_warshall(arr,rst,N)

for i in range(N):
    for j in range(N):
        if rst[i][j] == INF:
            stdout.write("0 ")
        else :
            stdout.write("1 ")
    stdout.write("\n")






