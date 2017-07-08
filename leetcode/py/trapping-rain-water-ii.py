
import heapq

class tupleItem(object):
    def __init__(self, x, y, h):
        self._r = x
        self._c = y
        self._h = h

    def __lt__(self, other):
        return self._h < other.get_h()
    def get_r(self):
        return self._r
    def get_c(self):
        return self._c
    def get_h(self):
        return self._h

class Solution(object): 
    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        hp = []
        row = len(heightMap)
        if row <= 1:
            return 0
        col = len(heightMap[0])
        if col <= 1:
            return 0
        
        visited = []
        for r in range(0, row):
            visited.append([])
            for c in range(0, col):
                visited[r].append(False)
        for r in range(0, row):
            ob = tupleItem(r, col-1, heightMap[r][col-1] )
            visited[r][col-1] = True
            heapq.heappush(hp, ob)
            ob = tupleItem(r, 0, heightMap[r][0] )
            visited[r][0] = True
            heapq.heappush(hp, ob)
        for c in range(0, col):
            ob = tupleItem(0, c, heightMap[0][c] )
            heapq.heappush(hp, ob)
            visited[0][c] = True
            ob = tupleItem(row-1, c, heightMap[row-1][c])
            heapq.heappush(hp, ob)   
            visited[row-1][c] = True
        

        res = 0
        _max = 0
        direction = [[0, -1], [0, 1], [1, 0], [-1, 0]]
        while hp:
            t = heapq.heappop(hp)
            r, c, h = t.get_r(), t.get_c(), t.get_h()
            _max = max(h, _max)
            def in_range(x, y, row, col):
                if x >= 0 and x < row and y >= 0 and y < col:
                    return True
                return False
            for (rd, cd) in direction:
                x = r + rd
                y = c + cd
                if in_range(x, y, row, col) and visited[x][y] == False:
                    visited[x][y] = True
                    if heightMap[x][y] < _max:
                        res += _max - heightMap[x][y]
                    ob = tupleItem(x, y, heightMap[x][y])
                    heapq.heappush(hp, ob)
        return res

a = Solution()
matrix = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
matrix = [[12,13,1,12],[13,4,13,12],[13,8,10,12],[12,13,12,12],[13,13,13,13]]
print(a.trapRainWater(matrix))