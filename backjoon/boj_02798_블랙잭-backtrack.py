"""
boj_2798_블랙잭(난이도 : 브론즈 2)
기본적인 백트랙킹 문제
"""

a, b = input().split(' ')
a = int(a)
b = int(b)

arr = list(input().split(' '))
for i in range(len(arr)):
    arr[i] = int(arr[i])

arr.sort()

global rst
rst = 0

def backtrack(arr, now, cnt, sum, limit):
    global rst
    if cnt==3 :
        rst = max(rst,sum)
        return

    if now == len(arr):
        return

    backtrack(arr,now+1,cnt,sum,limit)
    if arr[now] + sum <= limit:
        backtrack(arr,now+1,cnt+1, arr[now] + sum, limit)

backtrack(arr,0,0,0,b)
print(rst)