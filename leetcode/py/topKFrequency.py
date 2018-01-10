class Solution:
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        class KV:
            def __init__(self):
                self.k = ''
                self.v = 0
            """    
            def __cmp__(self, other):
                if self.v > other.v:
                    return 1
                elif self.v == other.v:
                    if self.k < other.k:
                        return 1
                    elif self.k == other.k:
                        return 0
                    else:
                        return -1
                return -1
            """
            def __eq__(self, other):
                return self.v == other.v and self.k == self.k
            
            def __lt__(self, other):
                if self.v != other.v:
                    return self.v < other.v
                if self.v == other.v:
                    return self.k > other.k
                    
        
        kv_arr = []        
        kv_dict = {}
        for it in words:
            if it in kv_dict:
                kv_dict[it] += 1
            else:
                kv_dict[it] = 1
        # or heapify
        # 
        for kk, vc in kv_dict.items():
            kv_item = KV()
            kv_item.k = kk
            kv_item.v = vc
            kv_arr.append(kv_item)

        
        arr = []
        arr_tmp = []
        for it in kv_arr:   
            heapq.heappush(arr, it)
            if len(arr) > k:
                heapq.heappop(arr)
                
        arr_ret = []
        for idx in range(k):
            it = heapq.heappop(arr)
            arr_ret.append(it.k)
        return arr_ret[::-1]
        