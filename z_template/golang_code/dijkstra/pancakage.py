 
def pan(s, n):
    return n
t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case 
  res = pan(n[0], int(n[1]))
  print("Case #{}: {} ".format(i, res))
#for it in 
  


