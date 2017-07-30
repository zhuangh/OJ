
"""
def DFS(rev_kids, st, no):
     
    h = 0 
    for it in rev_kids:
        if it != no:
            h = max(h, DFS(rev_kids, it, no))
    return h
"""

def BFF(kids):
    if len(kids) == 0:
        return 0
    if len(kids) == 1:
        return 1
    # check maximum cycle
    sz = len(kids)
    res_c = 1
    res_2 = 0
    in_path = [0] * sz
    #print(in_path)
    cycle_len_2 = []
    for i in range(0, sz):
        j = i 
        done = [False] * sz
        l = 0
        while not done[j]:
            done[j] = True
            j = kids[j]
            #print(j)
            #in_path[j] = max(in_path[j], l)
            l += 1
        if i == j: 
            if l == 2:
                # check cycle length == 2
                cycle_len_2.append((i, kids[i]))
            else:
                res_c = max(res_c, l)
    #for (i, j) in cycle_len_2:
    #    res_2 += DFS(rev_kids, i, j) + DFS(rev_kids, j, i) + 2
    for i in range(0,sz):
        for j in range(0,sz):
            if kids[kids[j]] == j: 
                continue
            in_path[kids[j]] = max(in_path[kids[j]], in_path[j]+1)
    
    #print(in_path)
    for (i, j) in cycle_len_2:
        #print(i, in_path[i], j, in_path[j])
        res_2 += in_path[i] + in_path[j] + 2 
    
    return max(res_c, int(res_2/2))

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
  kids_num = int(input())
  #n, m = [int(s) for s in input().split(" ")]  # read a list of integers, 2 in this case
  kids = [int(s) - 1 for s in input().split(" ")]
  """
  rev_kids = {}
  for it, to in  enumerate(kids):
        if to not in rev_kids:
           rev_kids[to] = []
        rev_kids[to].append(it)
"""
  #print(kids)
  print("Case #{}: {}".format(i, BFF(kids)))
  # check out .format's specification for more formatting options
