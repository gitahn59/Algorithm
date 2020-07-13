"""
boj_10816_숫자 카드 2(난이도 : 실버4)
Map을 이용한 탐색
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








