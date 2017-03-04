


class Solution(object):
    def __init__(self):
        self.length = 0
        self.path = []
        self.graph = {}
        self.visit = {}

    def construct_graph(self, tickets):
        for it in tickets:
            from_, to_ = it[0], it[1]
            #print(from_)
            if from_ in self.graph:
                self.graph[from_].append(to_)
                self.visit[from_].append(False)
            else:
                self.graph[from_] =[]
                self.graph[from_].append(to_)
                self.visit[from_] = []
                self.visit[from_].append(False)

            if to_ not in self.graph:
                self.graph[to_] = []
                self.visit[to_] = []

        for it in self.graph:
            self.graph[it].sort()
            #print(self.graph[it])
	#return graph, visit

    def dfs(self,start):
        self.path.append(start)
        #print(self.path)
        if len(self.path) == self.length:
            return True
        for it, _ in enumerate(self.graph[start]):
            if self.visit[start][it] == False:
                self.visit[start][it] = True
                if self.dfs(self.graph[start][it]) == True:
                    return True
                self.visit[start][it] = False
        self.path.pop()
        return False

    def findItinerary(self, tickets):
        """
	:type tickets: List[List[str]]
	:rtype: List[str]
        """

        self.length = len(tickets)+1
        #print(self.length)
        #graph, visit = 
        self.construct_graph(tickets)
        self.dfs("JFK")
        #print(graph["JFK"])
        return self.path
	
a = Solution()
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
tickets = [["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
print(a.findItinerary(tickets))

