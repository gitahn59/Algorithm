"""
boj_1003_피보나치 함수(난이도 : 실버3)
topdown dp를 사용한 피보나치 함수 응용
"""

import sys
global a, b, mem
mem = [[-1,-1] for i in range(0,41)]

def fibonacci(n):
    global mem
    if mem[n][0]==-1:
        a = fibonacci(n-1)
        b = fibonacci(n-2)
        mem[n] = [a[0]+b[0], a[1]+b[1]]
        return mem[n]
    else :
        return mem[n]

N = int(str(sys.stdin.readline()).rstrip())

mem[0] = [1,0]
mem[1] = [0,1]

for n in range(N):
    num = int(str(sys.stdin.readline()).rstrip())
    fibonacci(num)
    print('%d %d' % tuple(mem[num]))



