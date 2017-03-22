
# do not use this class, TLE
class TrieTree(object):
    def __init__(self):
        self.child = [None, None] # [for 0 and for 1]

class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # build a trie
        trie_tree = [None, None]
        #print(nums)
        #print(trie_tree.child[1])
        for num in nums:
            root = trie_tree
            #print(num)
            for i in range(31,-1,-1): # watch out the lower bound of the range function
                curbit = (num>>i) & 1 
                if root[curbit] is None:
                    NewNode = [None, None]
                    root[curbit] = NewNode
                    root = NewNode
                else:
                    root = root[curbit]
            
        # go through the nums
        max_xorsum = 0 
        for num in nums:
            trie = trie_tree
            xorsum = 0
            #print(num)
            for i in range(31,-1,-1): 
                curbit = (num >> i) & 1
                if trie[ (curbit^1) ] is not None:
                    xorsum += (1 << i)
                    trie = trie[ (curbit^1) ]
                else:
                    trie = trie[curbit]
            #print(xorsum)
            max_xorsum = max(xorsum, max_xorsum)
        return max_xorsum


a = Solution()
nums = [3, 10, 5, 25, 2, 8]
nums = [4, 6, 7]
print(a.findMaximumXOR(nums))
