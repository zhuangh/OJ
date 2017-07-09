from heapq import heappush, heappop
class Solution:
    """
    @param nums: A list of integers.
    @return: The median of numbers
    """
    def medianII(self, nums):
        # write your code here
        sz = len(nums)
        if sz == 0 or sz == 1:
            return nums
        ret = []
        ret.append(nums[0])
        min_heap = []
        min_heap.append(-nums[0])
        max_heap = []
        cnt = 1        
        for ele in nums[1::]:
            #print(ele)    
            cnt += 1
            if cnt % 2 == 1: #insert to min heap
                t = heappop(max_heap) # assume the number are non-negative
                #print(t)
                if ele > t:
                    heappush(min_heap, -t)
                    heappush(max_heap, ele)
                else:
                    heappush(min_heap, -ele) 
                    heappush(max_heap, t)
            else: # insert to max_heap            
                t = -heappop(min_heap)
                if ele < t:
                    heappush(min_heap, -ele)
                    heappush(max_heap, t)
                else:
                    heappush(max_heap, ele)
                    heappush(min_heap, -t)
            
            #print(min_heap, max_heap) 
            ret.append(-min_heap[0])
        return ret

a = Solution()
nums = [1,2,3,4,5]
print(a.medianII(nums))