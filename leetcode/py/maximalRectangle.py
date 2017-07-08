def print_hm(h):
    r = len(h)
    c = len(h[0])
    for i in range(1, r):
        for j in range(1, c):
            print(h[i][j], end='\t')
        print()
    
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # sol: h[j]*(right[j]-left[j]+1) for i and j
        # complexity: O(n^2)
        # space O(n^2) # input 

        r = len(matrix)
        if r == 0: return 0
        c = len(matrix[0])
        h = []
        left = [] 
        right = []
        res = 0
        for j in range(0, c):
            h.append(0)
            left.append(0)
            right.append(c-1)
       
        for i in range(0, r):
            left_cur = 0 
            right_cur = c-1
            for j in range(0, c):
                if matrix[i][j] == '1': h[j]=h[j]+1
                else: h[j]=0
            for j in range(0, c):
                if matrix[i][j] == '1': 
                    left[j] = max(left[j], left_cur) 
                    # depends on the most right last row seen, when following the last row height
                else: 
                    left[j] = 0 # lower the height here, so not constraint 
                    left_cur = j+1 # reset

            for j in range(c-1, -1, -1):
                if matrix[i][j]=='1': 
                    right[j] = min(right_cur, right[j]) 
                    # depends on the most left last row seen, when following the last row height
                else: 
                    right[j] = c-1 # lower the height here, so not constraint 
                    right_cur = j-1 #reset
            #print(i, matrix[i], left, right, h)
            for j in range(0, c):
                res_tmp = h[j]*(right[j]-left[j]+1) 
                if res_tmp > res: res = res_tmp
        return res


    def maximalRectangle1(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        # sol(i,j) = max_{t=1,j} h(i,j-t+1)*t
        # complexity O(n^3)
        
        r = len(matrix)
        if r == 0: return 0
        c = len(matrix[0])
        h = []
        res = 0
        for i in range(0, r+1):
            na = []
            for j in range(0, c+1):
                na.append(0)
            h.append(na)
        for i in range(1, r+1):
            for j in range(1, c+1):
                if matrix[i-1][j-1] == '1':
                    h[i][j] = h[i-1][j] + 1
        #print_hm(h)

        for i in range(1, r+1):
            for j in range(1, c+1):
                hs = h[i][j]
                if matrix[i-1][j-1] != '1': continue
                for w in range(j, 0, -1):
                    if matrix[i-1][w-1] != '1': break
                    hs = min(hs, h[i][w])
                    #print('i', i, ' j', j, ':' , hs,'x', (j-w+1))
                    #print('---')
                    res_tmp = hs * (j-w+1)
                    if res < res_tmp:
                        res = res_tmp
        return res


a = Solution()
matrix = ["10100","10111","11111","10010"]
#matrix = ["01101","11010","01110","11110","11111","00000"]
print(a.maximalRectangle(matrix))