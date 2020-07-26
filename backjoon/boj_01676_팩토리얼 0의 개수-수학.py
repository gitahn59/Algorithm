"""
boj_1676_팩토리얼 0의 개수(난이도 : 실버3)
수학
소인수 분해를 통해 2, 5의 개수를 각각 카운팅하여
min(2,5)의 개수가 0의 개수가 됨
"""

import sys

N = int(sys.stdin.readline().rstrip())
cnt2=0
cnt5=0

for n in range(2, N+1):
    while n % 2 == 0:
        n = n // 2
        cnt2 +=1
    while n % 5 == 0:
        n = n // 5
        cnt5 +=1

print(min(cnt2,cnt5))




