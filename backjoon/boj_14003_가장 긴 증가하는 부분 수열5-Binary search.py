"""
boj_14003_���� �� �����ϴ� �κ� ���� 5(���̵� : ���1)
���� Ž��

ex)
6
10 20 1 2 3 50
1. (10)
2. (10, 20)
3. (1, 20) 10�� �ڸ��� �� �� ������ ���� �� �����Ƿ� ���� 
- �ĺ� (10, 20) (1)
4. (1, 2)
- �ĺ� (1,2) : (10,20)�� �ĺ��� Ż��
(1, 2, 3)
(1, 2, 3, 50)

Ǯ�� ) 
���� Ž���� ���� ���� ���Ұ� �� idx�� ã��
�� idx�� ���� ���Ͽ� �� ������ ��ü�� (���߿� ���� ���ҿ� �񱳵�)
�� ������ ���� ���� ���ҷδ� �ִ� ���̴� �ƴ� �� ������
���߿� ���� ���ҵ�� ������ �ִ� ���̷� ���ŵ� �� �ִ� ��츦
����� �� �� ����
"""

from sys import stdin, stdout
from math import sqrt
from bisect import bisect_left
from itertools import permutations

N = int(stdin.readline().rstrip())
arr = list(map(int, stdin.readline().rstrip().split(' ')))
cnt = [1 for i in range(N)]

brr = [arr[0]]
rlimit = 0
now = arr[0]

for i in range(N):
    idx = bisect_left(brr, arr[i])
    if idx < len(brr) :
        if brr[idx] > arr[i]:
            brr[idx] = arr[i]
    else :
        brr.append(arr[i])
        rlimit = i
        now = arr[i]
    cnt[i] = idx + 1

length = len(brr)
stdout.write(str(length)+'\n')
rst = [now]
length -= 1

for i in range(rlimit-1, -1, -1):
    if cnt[i] == length and arr[i] < now:
        rst.append(arr[i])
        length-=1
        now = arr[i]
    if length == 0:
        break;

rst.reverse()

for i in rst:
    stdout.write(str(i)+' ')
stdout.write('\n')






