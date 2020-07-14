"""
boj_9095_1,2,3 더하기(난이도 : 실버3)
dp
기본적인 topdown dp
"""

import sys

global mem
mem = [0 for i in range(12)]
mem[0] = 0
mem[1] = 1
mem[2] = 2
mem[3] = 4

T = int(str(sys.stdin.readline()).rstrip())

def solve(num):
    global mem
    if mem[num]==0:
        mem[num] = solve(num-3) + solve(num-2) + solve(num-1)
        return mem[num]
    else :
        return mem[num]

for t in range(T):
    num = int(str(sys.stdin.readline()).rstrip())
    print(solve(num))






