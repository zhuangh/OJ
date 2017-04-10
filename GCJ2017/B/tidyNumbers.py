
def next_number(n):
  sz = len(n)
  j = 0
  while True:  
    #print(n[i])
    if (j == sz-1) :
      break
    if (int(n[j]) > int(n[j+1])):
      break
    else :
      j+=1

  nn = ''

  for i in range(0,j):
    nn += n[i]
  if j < sz - 1:
    nn += str(int(n[j])-1)
  else:
    nn += str(int(n[j]))
  for i in range(j+1,sz):
    nn += '9'

  return j, nn

def tidy_helper(n):
  n = str(n)
  while True:
    #print(n)
    j, n = next_number( n )
    if j == len(n)-1:
      break
  return int(n)

t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [s for s in input().split(" ")]  # read a list of integers, 2 in this case  
  res = tidy_helper(n[0])
  print("Case #{}: {}".format(i, res))


