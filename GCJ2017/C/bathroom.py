
"""
def check(reg):
    if reg%2 ==0:
        return (reg)/2, (reg)/2-1
    return (reg-1)/2, (reg-1)/2
def bath(n,k):
    times = 0 
    while k > 0 :
        k = (k >> 1)
        times+=1
    reg = int( n/(2**(times-1)) )
    #print(reg)
    maxlr, minlr = check(reg)
    return int(maxlr), int(minlr)
"""

from math import ceil, floor
import heapq 
from collections import defaultdict
def bath(n, k):
    S = []
    heapq.heappush(S, -n)
    C = defaultdict(int)
    C[n]=1
    P = 0
    while True:
        X = heapq.heappop(S)     
        X = -X   
        X0 = ((X)//2) # overflow of (999999999999999999 - 1)/2 = 5e17
        X1 = ((X-1)//2)
        P = P + C[X]
        if P >= k:
            return X0, X1
        else:
            if X0 not in C:
                heapq.heappush(S, -X0)
            C[X0] += C[X]    
            if X1 not in C:
                heapq.heappush(S, -X1)   
            C[X1] += C[X] 


t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [s for s in input().split(" ")]  # read a list of integers, 2 in this case 
  #res = pan(n[0], int(n[1]))
  #res = res if res != -1 else "IMPOSSIBLE"
  x, y = bath(int(n[0]) , int(n[1]))
  print("Case #{}: {} {}".format(i, x, y))
#for it in 
  


