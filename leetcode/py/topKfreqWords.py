class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        kv_dict = {}
        for it in nums:
            if it in kv_dict:
                kv_dict[it] += 1
            else:
                kv_dict[it] = 0
        
        class KV:
            def __init__(self):
                self.k = 0
                self.v = 0
            def __eq__(self, other):
                return self.v == other.v
            def __lt__(self, other):
                return self.v < other.v
                
        arr = [] 
        for kk, vv in kv_dict.items():
            kv_item = KV()
            kv_item.k = kk
            kv_item.v = vv
            heapq.heappush(arr, kv_item)
            if len(arr) > k:
                heapq.heappop(arr)
        ret = []
        for i in range(k):
            it = arr[i]
            ret.append(it.k)
        return ret[::-1]
        
        
        