import heapq

class Solution:
    def printKClosest(self, arr, k, x):
        heap = []

        for num in arr:
            if num == x:
                continue
            diff = abs(num - x)
            heapq.heappush(heap, (diff, -num))

        ans = []
        for _ in range(k):
            if heap:
                ans.append(-heapq.heappop(heap)[1])

        return ans
