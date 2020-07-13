"""
boj_10814_나이순 정렬(난이도 : 실버5)
안정 정렬
"""
import sys
N = int(sys.stdin.readline().rstrip())

arr = []
for n in range(N):
    s = list(sys.stdin.readline().rstrip().split(' '))
    s[0] = int(s[0])
    arr.append(s)

def mykey(n):
    return n[0]

arr.sort(key=mykey)

for n in range(N):
    print('%d %s' % (arr[n][0],arr[n][1]))
    








