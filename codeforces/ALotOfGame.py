

class TrieTree(object):
    def __init__ (self):
        self.root = dict()
        self.win = dict()  
        self.lose = dict()  
        
    def add(self, s):
        cur = self.root
        for it in s:
            if it not in cur: 
                cur[it] = {}
                self.win[it]={}
            cur = cur[it]
    
    def dfs(self, cur , from_it ):
        is_leaf = True
        for  to_it, it in cur.iteritems() :
            is_leaf = False
            self.dfs( it , from_it  ) 
            self.win[ from_it ] =  not self.win[to_it]

#if is_leaf :
        self.win[from_it] = False 
	

    def sol(self, k) :
        print(self.win['origin'])




n , k = [int(s) for s in raw_input().split(" ")]
tree =TrieTree() 
for i in xrange(0,n):
    tree.add(raw_input())

tree.dfs( tree.root, 'origin' ) 
tree.sol(k) 


