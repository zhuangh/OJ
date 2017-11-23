import copy
def precison_correct(n):
    #print(n)
    if abs(24 - n) < 1e-2:
        return 24
    return n
class Solution: 
    def permute_help(self, st, left, res):
        length = len(left)
        if length == 0: 
            res.append(st)
            return
        for i in range(length):
            st_tmp = copy.deepcopy(st) # Note here
            st_tmp.append(left[i])
            left_tmp = []
            for j in range(length):
                if i == j:
                    continue
                left_tmp.append(left[j])
            self.permute_help(st_tmp, left_tmp, res)

    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        length = len(nums)
        st = []
        self.permute_help(st, nums, res)
        return res

    def perm(self, nums):
        # return all the combination
        #nums_comb = []
        res = self.permute(nums)
        #nums_comb.append(nums)
        #print(nums_comb)
        #print(res)
        return res

    def check_24_2(self, a, b):
        if precison_correct(a+b) == 24 or (b != 0 and precison_correct(a*1.0 / b) == 24)\
             or precison_correct(a-b) == 24 or precison_correct(a*b) ==24:
            return 24
        return -1

    def check_24_3(self, a, b, c):
        if self.check_24_2(a*b, c) == 24 or self.check_24_2(a+b, c) ==24 \
           or (b!=0 and self.check_24_2(a*1.0/b, c) ==24) or self.check_24_2(a-b, c) ==24 \
           or self.check_24_2(a, b*c) == 24 or (c!=0 and self.check_24_2(a, b*1.0/c) == 24) \
           or self.check_24_2(a, b+c) == 24 or self.check_24_2(a, b-c) == 24:
                return 24
        return -1

    def check_24(self, nums):
        #print(nums)
        if self.check_24_3(nums[0]*nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0]+nums[1], nums[2], nums[3]) == 24 \
            or (nums[1] != 0 and self.check_24_3(nums[0]*1.0/nums[1], nums[2], nums[3]) == 24)\
            or self.check_24_3(nums[0]-nums[1], nums[2], nums[3]) == 24 \
            or self.check_24_3(nums[0], nums[1]*nums[2], nums[3]) == 24 \
            or (nums[2] != 0 and self.check_24_3(nums[0], nums[1]*1.0/nums[2], nums[3]) == 24) \
            or self.check_24_3(nums[0], nums[1], nums[2] * nums[3]) == 24 \
            or (nums[3] != 0 and self.check_24_3(nums[0], nums[1], nums[2]*1.0/nums[3]) == 24) :
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
nums = [8,4,7,1]  
nums = [1,5,1,3]
nums = [1,2,1,2]
nums = [1,3,4,6]

nums = [3,3,8,8]
print(nums)

print(a.judgePoint24(nums))