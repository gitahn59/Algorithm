"""
boj_6064_카잉 달력(난이도 : 실버1)
GCD(최대공약수), LCM(최소공배수)
최소공배수를 계산하여 검사 범위 식별
검사 범위 내에서 후보를 추출하고
각 후보에 대해 나머지 연산을 통해 조건을 만족하는지 확인

1, N, M 등의 임계값에 대해 세세한 처리가 필요함
"""

from sys import stdin, stdout

T = int(stdin.readline().rstrip())

def lcm(a,b):
    def gcd(a,b):
        if b == 0: return a
        else : return gcd(b, a%b)
    g = gcd(a,b)
    a = a // g
    b = b // g
    return g * a * b

def solve():
    M, N, x, y = map(int,stdin.readline().rstrip().split(' '))
    if M==1 or N==1:
        return str(max(x,y))+'\n'
    LCM = lcm(M,N)
    if y == N : y = 0
    for i in range(x, LCM+1, M):
        if i % N == y:
            return str(i)+'\n'    
    return '-1\n'

for t in range(T):
    stdout.write(solve())





