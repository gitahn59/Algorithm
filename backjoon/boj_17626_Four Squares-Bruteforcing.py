"""
boj_17626_Four Squares(난이도 : 실버5)
완전탐색
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left

def solve():
    N = int(stdin.readline().rstrip())
    M = int(sqrt(N))
    if M * M == N :
        return '1\n'
    one = []
    for m in range(1,M+1):
        one.append(m*m)
    one.sort()
    two = []
    for m in range(1,M+1):
        left = m*m
        for k in range(m,M+1):
            num = left + k*k
            if num == N :
                return '2\n'
            elif num > N :
                break
            two.append(num)
    two.sort()
    
    for i in two:
        idx = bisect_left(one, N-i)
        if idx < len(one) and N-i == one[idx]:
            return '3\n'

    for i in two:
        idx = bisect_left(two, N-i)
        if idx < len(two) and N-i == two[idx]:
            return '4\n'

stdout.write(solve())
    





