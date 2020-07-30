"""
boj_1966_������ ť(���̵� : �ǹ� 3)
deque
deque�� ����� ������ ť�� �ùķ��̼� �ϰ�
Ž�� �ӵ��� ���� �켱������ ����Ʈ�� �����Ͽ�
���� �켱���� Ȯ���� O(1)�� Ž����
���� ť�� �����µ� N^2�� �ɸ��Ƿ�
O(N^2) Ǯ�̰� ������
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations
from collections import deque

T = int(stdin.readline().rstrip())

test = list()

for t in range(T):
    N, M = map(int, stdin.readline().rstrip().split(' '))
    line = map(int, stdin.readline().rstrip().split(' '))
    arr = deque()
    candidate = []
    for i in enumerate(line) :
        arr.append(i)
        candidate.append(i[1])
    candidate.sort()
    candidate.reverse()
    
    for idx, num in enumerate(candidate):
        flag = False
        while True:
            i = arr.popleft()
            if num == i[1]: # �켱���� ������
                if M == i[0]:
                    flag = True
                break
            else :
                arr.append(i)
        if flag :
            stdout.write(str(idx+1)+'\n')
            break;



