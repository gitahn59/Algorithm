"""
boj_1018_ü���� �ٽ� ĥ�ϱ�(���̵� : �ǹ� 4)
�迭�� ũ�Ⱑ �۾� ����Ž�� ����
������ �� ����� �����ϴ� ���� �߿���
"""
N, M = str(input()).split(' ')
N = int(N)
M = int(M)

arr = [[0 for j in range(50)] for i in range(50)]

for i in range(N):
    s = str(input())
    for j in range(M):
        arr[i][j] = s[j]

one = list("WBWBWBWB")
two = list("BWBWBWBW")

t1 = [one,two,one,two,one,two,one,two]
t2 = [two,one,two,one,two,one,two,one]

rst = 64
for i in range(N-7):
    for j in range(M-7):
        a = 0
        b = 0
        for h in range(8):
            for w in range(8):
                if t1[h][w] != arr[i+h][j+w] :
                   a+=1      
                if t2[h][w] != arr[i+h][j+w] :
                   b+=1      
        rst = min(rst, a, b)

print(rst)