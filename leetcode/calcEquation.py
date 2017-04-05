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
            

    
# https://leetcode.com/problems/evaluate-division


a = Solution()
equations = [ ["a", "b"], ["b", "c"] ] 
values = [2.0, 3.0]
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]

print(equations)
print(values)
print(queries)
print(a.calcEquation(equations, values, queries))
