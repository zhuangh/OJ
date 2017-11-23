import copy
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


a = Solution()
nums = [1,2,3] 
print(a.permute(nums))