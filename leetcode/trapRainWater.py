 
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

class pairItem(object):
    def __init__(self, x,  h):
        self._x = x 
        self._h = h

    def __lt__(self, other):
        return self._h < other.get_h()
    def get_x(self):
        return self._x
    def get_h(self):
        return self._h

class Solution(object): 
    def trap(self, heightMap):
        """
        :type height: List[int]
        :rtype: int
        """
        hp = []
        row = len(heightMap)
        if row <= 1:
            return 0 
        
        visited = []
        for r in range(0, row):
            visited.append(False)

        ob = pairItem(0, heightMap[0])
        visited[0] = True
        heapq.heappush(hp, ob)
        ob = pairItem(row-1, heightMap[row-1] )
        visited[row-1] = True
        heapq.heappush(hp, ob)    

        res = 0
        _max = 0
        direction =   [1, -1]
        while hp:
            t = heapq.heappop(hp)
            xt, h = t.get_x(),  t.get_h()
            _max = max(h, _max)
            def in_range(x, row):
                if x >= 0 and x < row :
                    return True
                return False
            for r in direction:
                x = xt + r
                if in_range(x, row) and visited[x] == False:
                    visited[x] = True
                    if heightMap[x] < _max:
                        res += _max - heightMap[x]
                    ob = pairItem(x, heightMap[x])
                    heapq.heappush(hp, ob)
        return res

a = Solution()
hM = [0,1,0,2,1,0,1,3,2,1,2,1]
print(a.trap(hM))
