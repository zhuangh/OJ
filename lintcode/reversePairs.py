class Solution(object):
    def bitget(self, bit, idx):
        ret = 0
        while idx:
            ret += bit[idx]
            idx -= idx & (-idx)
        return ret

    def bitupdate(self, bit, idx):
        while idx < len(bit):
            bit[idx] += 1
            idx += idx & (-idx)

    def reversePairs(self, nums):
        # Binary Index Tree solution
        # initial the tree
        if not nums:
            return 0
        min_num = min(nums)
        res = []
        if min_num <= 0:
            nums = [a - min_num + 1 for a in nums]
        max_num = max(nums)
        bit = [0]*(max_num+1)
        for num in nums[::-1]:
            res.append(self.bitget(bit, num-1))
            self.bitupdate(bit, num)
        return sum(res)

# https://leetcode.com/problems/reverse-pairs/#/description
a = Solution()
b = [2,4,3,5,1]
print(a.reversePairs(b))
