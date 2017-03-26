
class Solution(object):
    def bitget(self, bit , idx):
        ret = 0 
        while idx :
            ret += bit[idx]
            idx -= idx & (-idx)
        return ret

    def bitupdate(self, bit, idx):
        while idx < len(bit):
            bit[idx] += 1
            idx += idx&(-idx)
            
    def countSmaller(self , nums):
        # Binary Index Tree solution
        # initial the tree
        if not nums:
            return []
        min_num = min(nums)
        res = []
        if min_num <= 0:
            nums = [ a - min_num + 1 for a in nums ] # mistke min_num <= 0 +=and a - min_num + 1
        max_num = max(nums)
        bit = [0]*(max_num+1)
        for num in nums[::-1]:
            res.append( self.bitget(bit, num-1)) # mistake num, should be num-1
            print(bit)
            self.bitupdate(bit,num)
        return res[::-1]
        
# update the frequency from the last num in the nums array 
# analysis: O( n*log(max_nums))

nums = [5 , 2, 6,1]

a = Solution()

print(a.countSmaller(nums))


nums = [-1,-1]

a = Solution()

print(a.countSmaller(nums))


