"""
boj_1259_팰린드롬수(난이도 : 브론즈1)
팰린드롬
"""

import sys

while True:
    num = sys.stdin.readline().rstrip()
    if num == '0' :
        break
    flag = True
    for i in range(0,len(num)//2):
        if num[i] != num[-i-1] :
            flag = False
            break
    if flag:
        print('yes')
    else :
        print('no')





