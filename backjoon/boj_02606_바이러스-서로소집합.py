"""
boj_2606_바이러스(난이도 : 실버3)
기본적인 서로소 집합 문제
"""
import sys

class DisjointSet:
    p = [i for i in range(0,101)]

    def getP(self, a):
        if self.p[a]==a:
            return a
        else:
            self.p[a] = self.getP(self.p[a])
            return self.p[a]

    def isSet(self, a, b):
        a = self.getP(a)
        b = self.getP(b)
        return a==b
    
    def union(self, a,b):
        a = self.getP(a)
        b = self.getP(b)
        if a<b:
            self.p[b] = a
        else:
            self.p[a] = b
        
ds = DisjointSet()
N = int(sys.stdin.readline().rstrip())
M = int(sys.stdin.readline().rstrip())

for m in range(M):
    line = sys.stdin.readline().rstrip().split(' ')
    a,b = int(line[0]),int(line[1])
    if ds.isSet(a,b):
        continue
    else :
        ds.union(a,b)

cnt=0
for i in range(2,N+1):
    if ds.getP(i)==1:
        cnt+=1

print(cnt)






