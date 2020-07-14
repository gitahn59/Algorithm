"""
boj_2630_������ �����(���̵� : �ǹ�3)
��������
�迭�� �����Ͽ� ���� �˻�
"""
import sys

N = int(str(sys.stdin.readline()).rstrip())
arr = []
for n in range(N):
    line = str(sys.stdin.readline()).rstrip().split(' ')
    arr.append(line)

def recursive(h,w,l):
    if l==1:
        if arr[h][w] == '0':
            return (1,0)
        else :
            return (0,1)
    rst=[]        
    ll = l//2
    rst.append(recursive(h,w,ll))
    rst.append(recursive(h,w+ll,ll))
    rst.append(recursive(h+ll,w,ll))
    rst.append(recursive(h+ll,w+ll,ll))

    flag = 1
    for i in rst:
        if i!=(1,0):
            flag = 0
            break;
    if flag == 1:
        return (1,0)
    
    flag = 1
    for i in rst:
        if i!=(0,1):
            flag = 0
            break;
    if flag == 1:
        return (0,1)
    s= [0,0]
    for i in rst:
        s[0] += i[0]
        s[1] += i[1]
    return s

rst = recursive(0,0,N)
print(rst[0])
print(rst[1])





