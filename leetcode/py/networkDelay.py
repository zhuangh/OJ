class Solution:
    def DFS(self, K, delay, graph):
        #if visited_map[K] == 1: return 0                
        for v, w in graph[K].items(): 
            if delay[K] + w < delay[v]:
                delay[v] = delay[K] + w
                self.DFS(v, delay, graph)#, visited_map)
        return -1
    
    def dijkstra(self, K, N, delay, graph, TIMEOUT):
        Q = set(range(N))                
        delay[K-1] = 0
        while len(Q) > 0:
            u = None
            for node in Q:
                if u == None or delay[node] < delay[u]:
                    u = node
            Q.remove(u)
            for v, w in graph[u].items():
                if delay[u] + w < delay[v]:
                    delay[v] = delay[u] + w
            #print(delay)
        d = max(delay)
        if d == TIMEOUT:
            d = -1
        return d
    
    def bellman_ford(self, K, N, delay, pre, graph, TIMEOUT):

        delay[K-1] = 0
        for i in range(N):
            for u, vs in graph.items():
                for v, w in vs.items():
                    if delay[v] > delay[u] + w:
                        delay[v] = delay[u] + w
            #print(delay)
        #for u, vs in graph.items():
        #    for v, w in vs:
        d = max(delay)
        if d == TIMEOUT:
            d = -1
        return d
    
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        graph = {}
        delay = []
        pre = []
        TIME_OUT = 100000
        for it in range(N):
            graph[it] = {}           
            delay.append(TIME_OUT)
            pre.append(-1)
        for list_it in times:        
            u, v, w = list_it
            graph[u-1][v-1] = w
        #return self.dijkstra(K, N, delay, graph, TIME_OUT)#, visited_map)                
        return self.bellman_ford(K, N, delay, pre, graph, TIME_OUT)
