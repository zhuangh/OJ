 
class TrieNode:
    def __init__(self):
        self.childs = dict()
        self.isWord = False
        self.win = False
        self.lose = False
 
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for letter in word:
            child = node.childs.get(letter)
            if child is None:
                child = TrieNode()
                node.childs[letter] = child
            else:
                if child.isWord == True:
                    child.isWord = False
                    child.lose = False
                    child.win = False
            node = child
        node.isWord = True
        node.win = False
        node.lose = True
 

def DFS(node):
    if node.isWord == True:
        return 
    
    nodes = node.childs 
    for it in nodes:
        #print(it)
        child = nodes.get(it)
        DFS(child)
        node.win |= not child.win
        node.lose |= not child.lose
    
def firstWinOrLose(ttree):
    node = ttree.root.childs
    for it in node: 
        #print(it)
        child = node.get(it)
        DFS(child) # first win, second win
        ttree.root.win |= not child.win
        ttree.root.lose |= not child.lose
 
        
    
n, k = [int(s) for s in raw_input().split(" ")]
tree =Trie() 
win=dict()
lose=dict()
for i in xrange(0,n):
    #print(i)
    s=raw_input()
    tree.insert(s)

firstWinOrLose(tree)
 
w = tree.root.win
l = tree.root.lose

if w == False:
    print('Second')
elif l:
    print('First')
elif k % 2 == 1:
    print('First')
else:
    print('Second')

"""    
if w and l:
    print('First')
elif w:
    if k%2==1:
        print('First')
    else:
        print('Second')
elif l == True: 
    print('Second')
"""
#tree.printDFS()
#tree.dfs( tree.root, 'origin' ) 
#tree.sol(k) 


