class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        smap = {}
        for it in s:
            if it in smap:
                smap[it] += 1
            else:
                smap[it] = 1
        ret = ''
        sret = sorted(smap.items(), key=lambda kv: kv[1], reverse=True)        
        
        for k, v in sret:
            for it in range(v):
                ret+=k
        return ret
            
        