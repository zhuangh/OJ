class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        sz = len(nums)
        max_prod = num[0]
        p = nums[0]
        n = nums[0]
        for i in range(1, sz):
            pp = max(nums[i]*p, max(nums[i], nums[i]*n))
            nn = min(nums[i]*p, min(nums[i], nums[i]*n)) # trace the path with negative * negative = positive
            p = pp
            n = nn
            max_prod = max_prod if max_prod > p else p
            #print(i, max_prod, p, n)
        return max_prod
    
a = Solution()
m = [2,3,-2,4, -2, -2, 2, -1]
print(a.maxProduct(m))