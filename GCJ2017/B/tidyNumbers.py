
def next_number(n):
  # find larget j, making N_j < N_{j+1}  
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

"""
def tidy_check(n):
  #print(n)
  last_digit = 0
  while True:
    #last_digit = 1
    a = n%10
    n = int(n/10)
    b = n%10
    last_digit += 1
    #print(n)
    if a < b: 
      return False, last_digit
    if n == 0:
      #print(last_digit)
      break 

  return True, last_digit
  #return False
"""
def tidy_helper(n):
  n = str(n)
  #print(n)
  #if n > 100000000000:  # pass in seconds if n > 100000000000: 
  #  return n  # possible timeout due to the exponential complexity
  #while True:
    #print(n)
    #flag, digit = tidy_check(n)  
    #if flag == True:
    #  return n
    #else:
    #n = next_number(n)
    #print(n)
  while True:
    #print(n)
    j, n = next_number( n )
    if j == len(n)-1:
      break
  return int(n)


#print(tidy_helper(1000))


t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [s for s in input().split(" ")]  # read a list of integers, 2 in this case 
  
  res = tidy_helper(n[0])
  print("Case #{}: {}".format(i, res))
#for it in 
  


