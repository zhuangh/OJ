 
#class TrieNode (object): 
"""
    def __init__(self):
        self.leaves={}
        self.idx = [] 
        self.tag = -1
"""

class Solution(object):

    def is_pal ( self, s ):
        return s == s[::-1]

    def is_pal_trie ( self, prefix, pal ):
        if not self.leaves :
            if self.is_pal( prefix , 0 , len(prefix)-1): 
	        pal.append( idx )
        else:
            for c in cur.leaves:
                self.is_pal_trie( prefix + c, pal  )

    def insert(self, word, i ,trie) :
        cur = trie 
        cnt = 0 
        for c in word:
            if not c in cur:
                cur[c] = {} 
            cur = cur[c]
            cnt += 1 
            tmp = word[cnt:]
            if tmp and self.is_pal(tmp):
                 cur.setdefault("idx",[]) 
                 cur["idx"].append(i)  
	
        cur["tag"] = i
        return trie

    def find(self , word, i , res, trie):
        cur = trie 
        cnt = 0 
        fail = False 

        for c in word:
            if not c in cur: 
                fail = True
                break
            cur = cur[c] 
            cnt += 1
            if "tag" in cur:
                tmp = cur["tag"]
                if tmp != -1 and tmp!=i and self.is_pal( word[cnt:]):
                    res.append([ tmp, i ]) 

        if not fail and  "idx" in cur :
             for it in cur["idx"]:
                 if it != i:
                     res.append([ it, i]) 

           
            #check pal for the left words of the target word
      

#class Solution(object):
    def palindromePairs(self, words):
        """
        : type words: List[str]
        :rtype: List[List[int]]
        """
        res = []
        trie ={}
#        trie = TrieNode()
        for i in xrange( len(words) ) :
            self.insert(words[i] , i, trie)  
        for i in xrange( len(words) ): 
            self.find(words[i][::-1], i, res, trie)

        if "" in words:  # check for "" case
            idx = words.index("")
            tidx = 0 
            for it in words:
                if it != "":
                   if self.is_pal( it ):
                       res.append([idx, tidx])
                       res.append([tidx, idx]) 
                tidx += 1
    
        return res  
 
