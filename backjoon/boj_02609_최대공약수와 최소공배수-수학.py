"""
boj_2609_최대공약수와 최소공배수(난이도 : 실버 5)
수학
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