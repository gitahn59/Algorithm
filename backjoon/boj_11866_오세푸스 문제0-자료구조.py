"""
boj_11866_����Ǫ�� ���� 0(���̵� : �ǹ�4)
�ڷᱸ��
"""

import sys
from collections import deque

N, K = sys.stdin.readline().rstrip().split(' ')
N = int(N)
K = int(K)

arr = deque(range(1,N+1))

print("<", end='')
for n in range(1,N):
    for k in range(1,K):
        temp = arr.popleft()
        arr.append(temp)
    print(arr.popleft(), end=', ')
print('%d>'% arr[0])





