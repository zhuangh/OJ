
import bisect 
class BSTNode(object):
    def __init__(self, data=None, left=None, right=None, cnt = 1):
        self.data = data
        self.left = left
        self.right = right
        self.cnt = cnt

def insert(bstnode, data):
    if bstnode is None:
        #print(data)
        bstnode = data
    else:
        if data.data > bstnode.data:
            bstnode.cnt += 1
            #if bstnode.right is None:
            #    bstnode.right = data
            #else:
            insert(bstnode.right, data)
        elif data.data <= bstnode.data:
            #
            #if bstnode.left is None:
            #    bstnode.left = data
            #else:
            insert(bstnode.left, data)
        #else:
        #    bstnode.cnt += 1
    return

def pre_order_print(root):
    if not root:
        return
    print(root.data, root.cnt)
    pre_order_print(root.left)
    pre_order_print(root.right)


def getcnt(bstnode, data):
    if bstnode is None:
        return 0
    else:
        #print(res)
        res = 0 
        if data <= bstnode.data:
            res += bstnode.cnt
            res += getcnt(bstnode.left, data)
            #res += getcnt(bstnode.right, data)
        else:
            res += getcnt(bstnode.right, data)
        return res

class Solution(object):
    def reversePairs1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # binary search solution (n^2+nlogn)
        res = 0
        arr = [] 
        for ele in nums:
            res += len(arr) - bisect.bisect_left(arr, 2*ele+1) 
            bisect.insort_left(arr, ele) 
        return res

    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # BST
        res = 0
        if len(nums) == 0 or len(nums) == 1: 
            return 0 
        arr = BSTNode(data=nums[0])
        for ele in nums[1::]:
            res += getcnt(arr, ele*2 + 1) 
            #print(ele,res)
            #print(ele)
            e = BSTNode(data=ele)
            #print(e.data)
            insert(arr, e)
        #pre_order_print(arr)
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
