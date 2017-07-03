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
print(a.maximalRectangle(matrix))