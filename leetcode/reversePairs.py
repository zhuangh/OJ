

import bisect
class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # O(n*t(n) +nlogn) where t(n) = n is of insort_left in worst case
        res = 0
        arr = [] 
        for ele in nums:
            res += len(arr) - bisect.bisect_left(arr, 2*ele+1) 
            bisect.insort_left(arr, ele) 
        return res
 
# https://leetcode.com/problems/reverse-pairs/#/description

# good solution reference
# https://discuss.leetcode.com/topic/79227/general-principles-behind-problems-similar-to-reverse-pairs
a = Solution()
b = [2,4,3,5,1]
print(a.reversePairs(b))
"""
print('--------')
b = [-2,-1,-3]
print(a.reversePairs(b))
print('--------')
b = [-5,-5]
print(a.reversePairs(b))
print('--------')
b = [-2,-3,-1]
print(a.reversePairs(b))
"""
