"""
boj_1931_ȸ�ǽǹ���(���̵� : �ǹ�2)
�׸���
������ ���� �׸��� Ž���� �����ϵ��� �����͸� ����
1. ȸ�� ����ð�, ���۽ð��� �������� �������� ����
2. ���� ����� �ð����� ȸ���� ���۽ð��� ������ �߰�
    2a �ð��� ��ġ�� ����
3. ����, ����ð��� ������ �߰�
"""

import sys

N = int(str(sys.stdin.readline()).rstrip())
arr = []
for n in range(N):
    s = str(sys.stdin.readline()).rstrip().split(' ')
    arr.append([int(s[0]),int(s[1])])

arr.sort(key = lambda n: (n[1],n[0]))

now = -1
cnt = 0
for i in arr:
    if i[0] >= now:
        cnt+=1
        now = i[1]

print(cnt)




