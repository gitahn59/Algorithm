"""
boj_1654_랜선 자르기(난이도 : 실버3)
이진탐색
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations
from collections import deque

K, N = map(int,stdin.readline().rstrip().split(' '))
arr = []
for k in range(K):
    num = int(stdin.readline().rstrip())
    arr.append(num)

arr.sort()
def getcnt(length):
    global arr
    cnt = 0
    for i in arr:
        cnt += i // length
    return cnt

rst = 1
def binSearch(l, r):
    global rst
    if l > r:
        return None
    mid = (l+r) // 2
    cnt = getcnt(mid)
    if cnt >= N:
        if rst < mid:
            rst = mid
        binSearch(mid+1,r)
    else:
        binSearch(l,mid-1)

binSearch(1 , arr[-1])
print(rst)





