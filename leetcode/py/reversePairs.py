
import bisect 
class BSTNode(object):
    def __init__(self, data=None, left=None, right=None, cnt = 0):
        self.data = data
        self.left = left
        self.right = right
        self.cnt = cnt

def insert(bstnode, data):
    if bstnode is None:
        #print(data)
        bstnode = BSTNode(data=data)
    elif data > bstnode.data:
        insert(bstnode.right, data)
    elif data < bstnode.data:
        insert(bstnode.left, data)
    else:
        bstnode.cnt += 1

def getcnt(bstnode, data):
    if bstnode is None:
        return 0
    else:
        res = 0
        print(bstnode.data)
        if bstnode.data == data:
            res += bstnode.cnt
        res+= getcnt(bstnode.left, data)
        res+= getcnt(bstnode.right, data)
        return res

class Solution(object):
    def reversePairs1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0
        arr = [] 
        for ele in nums:
            res += len(arr) - bisect.bisect_left(arr, 2*ele+1) 
            bisect.insort_left(arr, ele) 
        return res

    def reversePairs(self, nums):
        res = 0
        arr = None
        for ele in nums:
            res += getcnt(arr, 2*ele+1) 
            #print(ele)
            insert(arr, ele) 
        return res


# https://leetcode.com/problems/reverse-pairs/#/description
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
