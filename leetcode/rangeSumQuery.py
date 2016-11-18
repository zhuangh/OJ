
# interesting code for the weak test bench 
# https://leetcode.com/discuss/70427/0-lines-python  
class NumArray(object):
    def __init__(self, nums) : 
	self.update = nums.__setitem__ 
	self.sumRange = lambda i, j : sum(nums[i:j+1]) 


