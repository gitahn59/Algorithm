"""
boj_17144_미세먼지 안녕!(난이도 : 골드5)
시뮬레이션
문제에 제시된 조건에 맞게 시뮬레이션
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations
from collections import deque  

R, C, T = map(int,stdin.readline().rstrip().split(' '))
arr = []

for r in range(R):
    line = list(map(int,stdin.readline().rstrip().split(' ')))
    arr.append(line)

condition = [0,0]
for r in range(R):
    if arr[r][0] == -1:
        arr[r][0] = 0
        arr[r+1][0] = 0
        condition[0] = r
        condition[1] = r +1
        break;

move = ((1,0),(-1,0),(0,1),(0,-1))

def diffuse(arr, R, C):
    box = []
    for r in range(R):
        for c in range(C):
            if arr[r][c] >= 5 :
                cnt = 0
                num = arr[r][c] // 5
                for a,b in move:
                    i = r + a
                    j = c + b
                    if i < 0 or i==R or j < 0 or j == C or (j == 0 and i in condition):
                        continue
                    cnt +=1
                    box.append((i,j,num))
                arr[r][c] -= num * cnt
    for r,c,num in box:
        arr[r][c] += num

def wind(arr, R, C):
    # 위쪽
    for i in range(condition[0]-1,0,-1):
        arr[i][0] = arr[i-1][0]
    for c in range(0,C-1):
        arr[0][c] = arr[0][c+1]
    for r in range(0,condition[0]):
        arr[r][C-1] = arr[r+1][C-1]
    for c in range(C-1,0,-1):
        arr[condition[0]][c] = arr[condition[0]][c-1]
    # 아래쪽
    for r in range(condition[1]+1,R-1):
        arr[r][0] = arr[r+1][0]
    for c in range(0,C-1):
        arr[R-1][c] = arr[R-1][c+1]
    for r in range(R-1, condition[1], -1):
        arr[r][C-1] = arr[r-1][C-1]
    for c in range(C-1,0,-1):
        arr[condition[1]][c] = arr[condition[1]][c-1]
    
for t in range(T):
    diffuse(arr,R,C)
    wind(arr,R,C)

rst = 0
for line in arr:
    rst += sum(line)
print(rst)





