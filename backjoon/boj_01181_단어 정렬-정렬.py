"""
boj_1181_�ܾ� ����(���̵� : �ǹ�5)
���ı����� 2��
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





