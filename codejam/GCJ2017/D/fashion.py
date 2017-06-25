
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

t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [s for s in input().split(" ")]  # read a list of integers, 2 in this case 
  #res = pan(n[0], int(n[1]))
  #res = res if res != -1 else "IMPOSSIBLE"
  x, y = bath(int(n[0]) , int(n[1]))
  print("Case #{}: {} {}".format(i, x, y))
#for it in 
  


