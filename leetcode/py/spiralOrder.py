class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        n = len(matrix)
        if n == 0 : return []
        m = len(matrix[0])
        if m == 0 : return [] 
        res = []
        col_left = 0 
        col_right = m - 1 
        row_upper = 0
        row_lower = n - 1
        while True:
            for x_inc in range(col_left, col_right+1, 1):
                res.append(matrix[row_upper][x_inc])
            row_upper += 1 
            if row_upper > row_lower: break
            for y_inc in range(row_upper, row_lower+1, 1):
                res.append(matrix[y_inc][col_right])
            col_right -=1 
            if col_right < col_left : break
            for x_dec in range(col_right, col_left-1, -1):
                res.append(matrix[row_lower][x_dec])
            row_lower-=1
            if row_lower < row_upper: break 
            for y_dec in range(row_lower, row_upper-1, -1):
                res.append(matrix[y_dec][col_left])
            col_left += 1
            if col_right < col_left : break
        return res

a = Solution()
matrix = [[1,2,3,4],[4,5,6,8],[7,8,9,10]]
a.spiralOrder(matrix)
