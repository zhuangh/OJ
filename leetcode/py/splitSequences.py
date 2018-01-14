class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        tail_len_trace = {}
        for it in nums: 
            if it - 1 not in tail_len_trace:
                if it not in tail_len_trace:
                    tail_len_trace[it] = []
                heapq.heappush(tail_len_trace[it], 1)
            else:
                l = heapq.heappop(tail_len_trace[it-1])
                if it  not in tail_len_trace:
                    tail_len_trace[it] = []
                heapq.heappush(tail_len_trace[it], l+1)
                if len(tail_len_trace[it-1]) == 0:
                    del tail_len_trace[it-1]
        #print(tail_len_trace)
        for ending, arr in tail_len_trace.items():
            for it in arr:
                if it < 3: 
                    return False
        return True