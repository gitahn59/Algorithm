"""
boj_10816_���� ī�� 2(���̵� : �ǹ�4)
Map�� �̿��� Ž��
"""
import sys
N = int(sys.stdin.readline().rstrip())

arr = list(sys.stdin.readline().rstrip().split(' '))
dic = {}
for i in arr:
   if i in dic:
       dic[i]+=1
   else :
       dic[i] = 1

M = int(sys.stdin.readline().rstrip())
arr = list(sys.stdin.readline().rstrip().split(' '))
for i in arr:
   if i in dic:
       print(dic[i])
   else :
       print(0)








