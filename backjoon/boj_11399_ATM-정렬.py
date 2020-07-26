"""
boj_11399_ATM(난이도 : 정렬)
정렬
"""

import sys

N = int(sys.stdin.readline().rstrip())
it = map(int, sys.stdin.readline().rstrip().split(' '))
arr = []
for i in it:
    arr.append(i)

arr.sort()
rst, now = (0,0)
for i in arr:
    rst = rst + i + now
    now += i 

print(rst)



