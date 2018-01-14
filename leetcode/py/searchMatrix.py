class Solution:
    def helper(self, matrix, x1, y1, x2, y2, target):
        if x1 > x2 or y1 > y2:
            return False
        xmid = int((x1 + x2)/2)
        ymid = int((y1 + y2)/2) 
        if target == matrix[xmid][ymid]:
            return True
        elif target < matrix[xmid][ymid] :
            xx2 = xmid - 1
            yy2 = ymid - 1
            return (self.helper(matrix, x1, y1, xx2, y2, target) or
                    self.helper(matrix, x1, y1, x2, yy2, target) )
        else:
            xx1 = xmid + 1
            yy1 = ymid + 1   
            return (self.helper(matrix, xx1, y1, x2, y2, target) or 
                    self.helper(matrix, x1, yy1, x2, y2, target) )
        
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        hlen = len(matrix)
        if hlen == 0:
            return False
        wlen = len(matrix[0])
        if wlen == 0:
            return False
        return self.helper(matrix, 0, 0, hlen-1, wlen-1, target)
        
