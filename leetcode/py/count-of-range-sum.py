import bisect

class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        
        
        """
        lower <= csum[i] - csum[j] <= upper
        => 
        csum[i] - upper <= csum[j] <= csum[i] - lower
        how many j 
        
        """
        its = 0 
        csum = 0 
        sum_list = [ 0, float('inf')]#[0 for _ in xrange(len(nums))]
        for it in nums:
            csum += it
            its += bisect.bisect_right(sum_list, csum-lower) - bisect.bisect_left(sum_list, csum-upper)
            bisect.insort(sum_list, csum)
        return its

if __name__ == '__main__':
    a = Solution()
    nums = [-2,5,-1]
    lower = -2
    upper = 2
    print(a.countRangeSum(nums,lower,upper))
