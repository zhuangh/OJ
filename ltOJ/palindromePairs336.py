 

class TrieNode: 
    def __init__(self):
        self.leaves={}
        self.idx = [] 
        self.tag = -1

    def is_pal ( self, s ):
        return s == s[::-1]


    def insert(self, word, i) :
        cur = self
        cnt = 0 
        for c in word:
            if not c in cur.leaves:
                cur.leaves[c] = TrieNode()
            cur = cur.leaves[c]
            cnt += 1 
            tmp = word[cnt:]
            if tmp and self.is_pal(tmp):
                 cur.idx.append(i) 
#        cur.idx.append(i) 
        cur.tag = i 

    def find(self , word, i , res):
        cur = self
        cnt = 0 
        fail = False

        for c in word:
            if not c in cur.leaves: 
                fail = True
                break
            cur = cur.leaves[c] 
            cnt += 1
            tmp = cur.tag
            if tmp != -1 and tmp!=i and self.is_pal( word[cnt:]):
                 res.append([ tmp, i ]) 

        if not fail and cur.idx :
             for it in cur.idx:
                 if it != i:
                     res.append([ it, i]) 

           
            #check pal for the left words of the target word
      

class Solution(object):
    def palindromePairs(self, words):
        """
        : type words: List[str]
        :rtype: List[List[int]]
        """

	res = []
        trie = TrieNode()
        for i in xrange( len(words) ) :
            trie.insert(words[i] , i)  
        for i in xrange( len(words) ):
            print("searching "+words[i][::-1])
            trie.find(words[i][::-1], i, res)

        if "" in words:  # check for "" case
            idx = words.index("")
            tidx = 0 
            for it in words:
                if it != "":
                   if trie.is_pal( it ):
                       res.append([ idx, tidx ])
                       res.append([tidx, idx]) 
                tidx += 1
    
        return res  

if __name__ == '__main__' :

    a = Solution()
    words = ["abcd", "dcba", "lls", "s", "sssll"]
    words = ["bat", "tab", "cat"]
    words = ["a", ""]
    words=["a","b","c","ab","ac","aa"]

#words = ["abc","cba", "cat","tac"]
#words = ["abbbbc", "abc", "abb", "ac"]

    print(words)
    print(a.palindromePairs(words))


