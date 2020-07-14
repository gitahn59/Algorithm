"""
boj_1764_�躸��(���̵� : �ǹ�4)
Dict
��ųʸ��� �̿��� ������ nlogn ����
"""

import sys

l = str(sys.stdin.readline()).rstrip().split(' ')
N, M = int(l[0]), int(l[1])

arr = {}
for n in range(N):
    name = str(sys.stdin.readline()).rstrip()
    arr[name]=0

for m in range(M):
    name = str(sys.stdin.readline()).rstrip()
    if name in arr:
        arr[name]+=1

rst = []
for k in arr:
    if arr[k] > 0 :
        rst.append(k)
rst.sort()
print(len(rst))
for i in rst:
    print(i)




