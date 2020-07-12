"""
boj_1181_단어 정렬(난이도 : 실버5)
정렬기준이 2개
"""

N = int(input())

arr = []
for i in range(N):
    s = input()
    arr.append(s)

def mykey(n):
    return (len(n), n)

arr = sorted(arr, key = mykey)

pre = ''
for i in range(N):
    if pre == arr[i]: 
        continue
    pre = arr[i]
    print(arr[i])





