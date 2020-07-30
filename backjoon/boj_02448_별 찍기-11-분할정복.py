"""
boj_2448_�� ��� - 11(���̵� : ���4)
��������
����Ż ������ ��Ģ���� ã�� ���� ���� �Լ� ����
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations

N = int(stdin.readline().rstrip())
M = N // 3
arr = [[' ' for i in range(5*M + (M-1))] for i in range(M * 3)]

pos = ((0,0),(1,-1),(1,1),(2,-2),(2,-1),(2,0),(2,1),(2,2))
def devide(arr, length, i, j):
    if length == 1:
        for p in pos:
            arr[i+p[0]][j+p[1]] = '*'
    else:
        devideLen = length//2
        devide(arr, devideLen, i,j)
        devide(arr, devideLen, i + 3*devideLen,j-6*devideLen//2)
        devide(arr, devideLen, i + 3*devideLen,j+6*devideLen//2)
devide(arr, M, 0, len(arr[0])//2)        

def myprint(arr):
    for line in arr:
        for i in line:
            stdout.write(i)
        stdout.write('\n')
myprint(arr)



