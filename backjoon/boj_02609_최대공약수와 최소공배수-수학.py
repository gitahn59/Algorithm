"""
boj_2609_�ִ������� �ּҰ����(���̵� : �ǹ� 5)
����
gcd 
"""
def gcd(a,b):
    if b==0: 
        return a    
    else: 
        return gcd(b, a%b)
        
a, b = input().split(' ')
a = int(a)
b = int(b)

g = gcd(a,b)
l = a / g
r = b / g
rst = g * l * r
print(g)
print(int(rst))