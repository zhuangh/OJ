 


def check(s, k, idx, lc, mc):
    
    if lc + mc != k:
        return False
    """
    print('---')
    print(idx)
    print(lc)
    print(mc)
    """
    for i in range(0,lc):
        #print(s[idx+i])
        if idx+i >= len(s):
            return False
        if s[idx+i] == '+':
            return False
    return True

def pan(s, k):
    n = 0
    mid_plus_cnt = 0
    left_minus_cnt = 0
    i = 0
    while i < len(s):
        #print(i)
        #print(s[i])
        #print('hello lc '+str(left_minus_cnt))
        #print('hello mc '+str(mid_plus_cnt))
        
        it = s[i]
        if it == '+':  
            if left_minus_cnt > 0: # mid + count 
                mid_plus_cnt += 1
            if mid_plus_cnt == k : 
                n+=2
                mid_plus_cnt = 0
            i += 1
            continue
                
        if it == '-' : 
            if mid_plus_cnt == 0: # left count -
                left_minus_cnt += 1
                if left_minus_cnt == k: 
                    n += 1 
                    left_minus_cnt = 0
                i += 1
            else:  # right count - 
                if check(s, k, i, left_minus_cnt, mid_plus_cnt) == True: #check right count is enough
                    mid_plus_cnt = 0
                    i += (left_minus_cnt )
                    left_minus_cnt = 0
                    n += 2
                else:
                    return -1
    if s[len(s)-1] == '+' and left_minus_cnt > 0:
        return -1
    if left_minus_cnt > 0:
        return -1
        
    return n

t = int(input())  # read a line with a single integer
for i in range(1, t+1):
  n = [s for s in input().split(" ")]  # read a list of integers, 2 in this case 
  res = pan(n[0], int(n[1]))
  
  #print(n[1])
  res = res if res != -1 else "IMPOSSIBLE"
  print("Case #{}: {}".format(i, res))
#for it in 
  


