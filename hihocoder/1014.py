class TrieTree(object):
    def __init__ (self):
        self.root = dict()  

    def add(self, s):
        cur = self.root 
        for it in s:
            if it not in cur:
                cur[it] = {} 
                cur = cur[it]
                cur['cnt'] = 1
            else:
                cur = cur[it]
                cur['cnt'] += 1

    def query(self, s):
        if len(s) == 0:
            return 0
        cur = self.root
        for it in s:
            if it not in cur:
                return 0
            else:
                cur = cur[it]
        return cur['cnt']  


if __name__ == '__main__':
    tree = TrieTree()
    for i in range(int(raw_input())):
        tree.add(raw_input())

    for i in range(int(raw_input())):
        print(tree.query(raw_input()))
    



