class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        mm = {}
        for it in s:
            if it in mm:
                mm[it] += 1
            else:
                mm[it] = 1
        for idx in range(len(s)):
            if mm[s[idx]] == 1:
                return idx
        return -1
    