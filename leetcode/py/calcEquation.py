# TODO: efficiency of runtime
# defaultdict?


class Solution(object):
    def dfs_search(self, eqmap, dag, visited, sfrom, sto):
        #print(sfrom)
        #if (sfrom, sto) not in eqmap:
        #    return -1.0, False
            
        #if sto == sfrom: # arrived the end of one query path
        #    return 1.0, True
        # keep searching, mark sfrom node as visited 
        #visited[sfrom] = 1
        # traverse the children node of sfrom
        #print(visited)
        if sfrom not in visited:
            return -1.0, False
        if sfrom == sto:
            return 1.0, True
        visited[sfrom] = 1
        #print(sfrom)
        for it in dag[sfrom]:
            #print(dag[sfrom])
            #print(sfrom, it)
            #print(visited)
            if  (sfrom, it) in eqmap and visited[it] == 0:
                #visited[it] = 1
                #print((sfrom, it))
                res, flag = self.dfs_search(eqmap, dag, visited, it, sto)
                if flag == True: # if one path is obtain
                    return res*eqmap[(sfrom, it)], True
                # there is no path seen from sfrom, return false and unmark visited of sfrom
        visited[sfrom] = 0
        return -1.0, False

     
    def calcEquation(self, equations, values, queries):
        ret = []
        eqmap = dict()
        dag = dict()
        visited = dict()
        sz = len(values)
        for it in range(0, sz):
            (sfrom, sto) = equations[it]
            if sfrom not in dag:
                dag[sfrom] = []
            dag[sfrom].append(sto)
            visited[sfrom] = 0
            eqmap[(sfrom, sto)] = values[it]
            if sto not in dag:
                dag[sto] = []
            dag[sto].append(sfrom)
            visited[sto] = 0
            eqmap[(sto, sfrom)] = 1.0/values[it]
            
        #print(eqmap)

        #print(dag)
        
        for it in queries:
            (sfrom, sto) = it
            res, flag = self.dfs_search( eqmap, dag, visited, sfrom, sto)
            for it in visited:
                visited[it]=0
                
            #print(visited)
            if flag == False:
                ret.append(-1.0)
            else:
                ret.append(res)
        return ret



    def calcEquationFloydWarshall(self, equations, values, queries):
        mm = collections.defaultdict(dict)
        for it in range(0, len(values)):
            (sfrom, sto) = equations[it]
            mm[sfrom][sto] = values[it]
            mm[sto][sfrom] = 1.0/values[it]
            mm[sfrom][sfrom] = 1
            mm[sto][sto] = 1
            
        #for it in queries:
        #    (sfrom, sto) = it 
        for k in mm:
            for i in mm[k]:
                for j in mm[k]:
                    mm[i][j] = mm[i][k] * mm[k][j]
                    
        return [mm[sfrom].get(sto, -1.0) for sfrom, sto in queries ]
            

 
    def calcEquationDFS(self, equations, values, queries):
        import collections
        Adj = collections.defaultdict(set)
        weight = {}
        for (x, y), z in zip(equations, values):
            weight[(x,y)]= z
            weight[(y,x)] = 1.00/z
            Adj[x].add(y)
            Adj[y].add(x)


        def DFS(u, v, product = 1.0, visited=set()):
            if u == v and Adj[u] :
                return product
            p = None
            visited.add(u)
            for x in Adj[u]:
                if x not in visited:
                    p = DFS(x, v, product*weight[(u, x)], visited)
                if p:
                    break
            visited.remove(u)
            return p

        ret = []
        for s, t in queries:
            p = DFS(s,t)
            ret.append(p if p else -1.0)
        return ret

        """
        Adj = collections.defaultdict(list)
        weights = {}  
        for (t, s), v in zip(equations, values):
            Adj[s] += t,
            Adj[t] += s,
            weights[(s, t)] = v
            weights[(t, s)] = 1. / v

        def DFS_visit(u, t, product=1., visited=set()):
            if u == t and Adj[u]: 
                return product
                
            visited.add(u)
            p = None
            for v in Adj[u]:
                if v not in visited:
                    p = DFS_visit(v, t, product * weights[(u, v)], visited)
                
                # If any search reaches t, then we are done. Otherwise, try others.
                if p:
                    break
            visited.remove(u)
            return p

        result = []
        for t, s in queries:
            p = DFS_visit(s, t) 
            result.append(p if p else -1.0)
                
        return result     
        """
    
# https://leetcode.com/problems/evaluate-division


a = Solution()
equations = [ ["a", "b"], ["b", "c"] ] 
values = [2.0, 3.0]
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]

print(equations)
print(values)
print(queries)
print(a.calcEquationDFS(equations, values, queries))
equations = [["a","b"],["b","c"],["bc","cd"]]
values=[1.5,2.5,5.0]
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
print(a.calcEquationDFS(equations, values, queries))
