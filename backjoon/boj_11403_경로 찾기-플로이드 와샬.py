"""
boj_11403_��� ã��(���̵� : �ǹ�1)
�÷��̵� �ͼ� �˰���
�÷��̵� �ͼ� 3�� ���� ������
ù��° ������ ���İ� ���
2,3��° ������ ����, ���� ��带 �����

def floyd_warshall(arr, rst, N):
    for k in range(N): # k�� ���İ� ��
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
    for k in range(N): # k�� ���İ� ��
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






