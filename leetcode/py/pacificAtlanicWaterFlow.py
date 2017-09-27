#!/bin/python



class Solution(object):
    def dfs(self, matrix, x, y, visited, xz, yz):
        """
        depth first
        """
        visited[x][y] = 1
        direction = [(-1, 0), (1,0), (0,1), (0, -1)]
        for (dx, dy) in direction:
            xt = x + dx
            yt = y + dy
            if xt < 0 or yt <0 or xt >= xz or yt >= yz:
                continue
            elif matrix[xt][yt] >= matrix[x][y]:
                if visited[xt][yt] == 1:
                    continue
                self.dfs(matrix, xt, yt, visited, xz, yz)

        #return False

    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        res = []
        xz = len(matrix)
        if xz == 0: 
            return []
        yz = len(matrix[0])
        if yz == 0:
            return []

        p_visited = [[False for _ in range(yz)] for _ in range(xz)]
        a_visited = [[False for _ in range(yz)] for _ in range(xz)]

        for i in range(xz):
            self.dfs(matrix, i, 0,    p_visited, xz, yz)
            self.dfs(matrix, i, yz-1, a_visited, xz, yz)

        for i in range(yz):
            self.dfs(matrix, 0,    i, p_visited, xz, yz)
            self.dfs(matrix, xz-1, i, a_visited, xz, yz)

        #print(p_visited)
        #print(a_visited)

        for i in range(xz):
            for j in range(yz):
                if p_visited[i][j] and a_visited[i][j]:
                    res.append([i,j])
        return res        

a = Solution()
mat = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
print(a.pacificAtlantic(mat))
