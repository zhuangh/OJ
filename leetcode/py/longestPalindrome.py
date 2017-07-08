def print_hm(h):
    r = len(h)
    c = len(h[0])
    for i in range(0, r):
        for j in range(0, c):
            print(h[i][j], end='\t')
        print()
    
def check(s):
    if s == s[::-1]:
        return True
    return False

class Solution(object):
    def longestPalindrome(self, s):
        # runtime LTE, but C++ solution is OK
        """
        :type s: str
        :rtype: str
        """
        res = ''
        sz = len(s)
        sr = s[::-1]
        mm = []
        e = 1
        tmp = 1
        if sz <= 1:
            return s
        for i in range(0, sz+1):
            nn = []
            for j in range(0, sz+1):
                nn.append(0) if i != j else nn.append(1)
            mm.append(nn)
        
        for k in range(2, sz+1):
            #print(k)
            for i in range(1, sz+1-k+1):
                j = i + k - 1
                #print(i,j)
                if s[i-1] == s[j-1] and (mm[i+1][j-1] > 0 or j == i+1):
                        mm[i][j] = (j - i)+1
                        if tmp <= mm[i][j]:
                            tmp = mm[i][j]
                            e = j

        #print_hm(mm)
        #print(tmp,e)
        return s[e-tmp:e]
    

a = Solution()
s = "babad"
#s = "abcdasdfghjkldcba"
#s = "aaaa"
s = "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
print(a.longestPalindrome(s))