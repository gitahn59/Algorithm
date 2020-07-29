"""
boj_14003_가장 긴 증가하는 부분 수열 5(난이도 : 골드1)
이진 탐색

ex)
6
10 20 1 2 3 50
1. (10)
2. (10, 20)
3. (1, 20) 10의 자리에 들어갈 수 있으며 값이 더 작으므로 갱신 
- 후보 (10, 20) (1)
4. (1, 2)
- 후보 (1,2) : (10,20)인 후보는 탈락
(1, 2, 3)
(1, 2, 3, 50)

풀이 ) 
이진 탐색을 통해 현재 원소가 들어갈 idx를 찾고
그 idx의 값과 비교하여 더 작으면 교체함 (나중에 나올 원소와 비교됨)
이 과정을 통해 현재 원소로는 최대 길이는 아닐 수 있지만
나중에 나올 원소들과 합쳐저 최대 길이로 갱신될 수 있는 경우를
기록해 둘 수 있음
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






