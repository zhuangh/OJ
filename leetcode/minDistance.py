def print_ww(ww, s1, s2):
    for i in range(0, s1):
        for j in range(0, s2):
            print(ww[i][j], end='\t')
        print()

class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        md = 0
        s1 = len(word1)
        s2 = len(word2)
        ww = []
        if s1 == 0: return s2
        if s2 == 0: return s1
        for i in range(0, s1+1):
            nl = []
            for j in range(0, s2+1):
                a = 0
                if i == 0: 
                    a = j
                else:
                    a = i if j == 0 else 0
                nl.append(a)
            ww.append(nl)
        for i in range(1, s1+1):
            for j in range(1, s2+1):
                if word1[i-1] != word2[j-1]:
                    t1 = min(ww[i-1][j], ww[i][j-1])
                    ww[i][j] = min(t1, ww[i-1][j-1])
                    ww[i][j] += 1
                else:
                    ww[i][j] = ww[i-1][j-1] 
        #print_ww(ww, s1+1, s2+1)
        return ww[s1][s2]


    
a = Solution()
"""
print(a.minDistance('abc','abcde'))
""" 
c="zoologicoarchaeologist"
d="zoogeologist"
print(a.minDistance(c,d))


c="logicoarchaeologist"
d="eologist"
print(a.minDistance(c,d))

c="pneumonoultramicroscopicsilicovolcanoconiosis"
d="ultramicroscopically"

print(a.minDistance(c,d))
