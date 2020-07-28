"""
boj_6064_ī�� �޷�(���̵� : �ǹ�1)
GCD(�ִ�����), LCM(�ּҰ����)
�ּҰ������ ����Ͽ� �˻� ���� �ĺ�
�˻� ���� ������ �ĺ��� �����ϰ�
�� �ĺ��� ���� ������ ������ ���� ������ �����ϴ��� Ȯ��

1, N, M ���� �Ӱ谪�� ���� ������ ó���� �ʿ���
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





