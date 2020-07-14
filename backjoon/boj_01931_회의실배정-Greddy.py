"""
boj_1931_회의실배정(난이도 : 실버2)
그리디
정렬을 통해 그리디 탐색이 가능하도록 데이터를 가공
1. 회의 종료시간, 시작시간을 기준으로 오름차순 정렬
2. 현재 진행된 시간보다 회의의 시작시간이 작으면 추가
    2a 시간이 겹치면 제외
3. 시작, 종료시간이 같으면 추가
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




