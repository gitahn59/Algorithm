"""
boj_18870_��ǥ ����(���̵� : �ǹ�2)
����, MAP
"""

import sys

N = int(str(sys.stdin.readline()).rstrip())
arr = sys.stdin.readline().rstrip().split(' ')
for i in range(0,len(arr)):
    arr[i] = int(arr[i])

srr = sorted(arr)
dict = {}
now = -1
for i in srr:
    if i in dict:
        continue
    else :
        now+=1
        dict[i]=now

for i in arr:
    print(dict[i],end=' ')
print()





