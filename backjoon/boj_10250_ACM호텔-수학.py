"""
boj_10250_ACMȣ��(���̵� : �����3)
����
"""

def solve(h, w, n):
    a = n % h
    if a==0:
        a = h
        b = (n//h)
    else :
        b = (n // h)+1
    return '%d%02d' %(a,b)

T = int(input())
for t in range(T):
    h, w, n = input().split(' ')    
    rst = solve(int(h), int(w), int(n))
    print(rst)





