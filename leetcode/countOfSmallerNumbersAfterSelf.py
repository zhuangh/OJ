import bisect 

class Solution(object):
    def countSmallerHelp(self , nums):
	"""
	    O(nlog(n))
	"""
        res = [0 for _ in xrange(len(nums)) ] 
        ni = []
        for it in xrange( len(nums) - 1, -1, -1):
	    pos = bisect.bisect_left(ni,nums[it])
            res[it] = pos 
            bisect.insort( ni, nums[it]) 
        return res 


    def countSmaller(self, nums):
	"""
	    :type nums: List[int]
	     :rtype: List[int]
        """
        new_nums = self.countSmallerHelp(nums)
        return new_nums



if __name__ == '__main__':
    a = Solution()
    nums = [5,4,1,10,0]
    print(nums)
    print(a.countSmaller(nums))

