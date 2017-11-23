class Solution:

    def perm(self, nums):
        # return all the combination
        nums_comb = []
        nums_comb.append(nums)
        #print(nums_comb)
        return nums_comb

    def check_24_2(self, a, b):
        if a+b == 24 or a*1.0 / b == 24 or a-b == 24 or a*b ==24:
            return 24
        return -1

    def check_24_3(self, a, b, c):
        if self.check_24_2(a*b, c) == 24 or self.check_24_2(a+b, c) ==24 \
           or self.check_24_2(a*1.0/b, c) ==24 or self.check_24_2(a-b, c) ==24 \
           or self.check_24_2(a, b*c) == 24 or self.check_24_2(a, b*1.0/c) == 24 \
           or self.check_24_2(a, b+c) == 24 or self.check_24_2(a, b-c) == 24:
                return 24
        return -1

    def check_24(self, nums):
        #print(nums)
        if self.check_24_3(nums[0]*nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0]+nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0]*1.0/nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0]-nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0], nums[1]*nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0], nums[1]*1.0/nums[2], nums[3]) == 24 :
                return True
        return False

    def judgePoint24(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #numstr = [str(i) for i in nums]
        #print(numstr)
        #numstr.append('(')
        #numstr.append(')')
        #print(numstr)
        #ops = ['+','-', '*' , '/', ')']
        nums_c = self.perm(nums)
        for it in nums_c:
            if self.check_24(it):
                return True
        return False
        
a = Solution()
nums = [8,4,7,1] #[4,1,8,7]
nums = [1,5,1,3]
print(nums)
print(a.judgePoint24(nums))