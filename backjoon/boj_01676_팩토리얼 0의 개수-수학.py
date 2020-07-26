"""
boj_1676_���丮�� 0�� ����(���̵� : �ǹ�3)
����
���μ� ���ظ� ���� 2, 5�� ������ ���� ī�����Ͽ�
min(2,5)�� ������ 0�� ������ ��
"""

import sys

N = int(sys.stdin.readline().rstrip())
cnt2=0
cnt5=0

for n in range(2, N+1):
    while n % 2 == 0:
        n = n // 2
        cnt2 +=1
    while n % 5 == 0:
        n = n // 5
        cnt5 +=1

print(min(cnt2,cnt5))




