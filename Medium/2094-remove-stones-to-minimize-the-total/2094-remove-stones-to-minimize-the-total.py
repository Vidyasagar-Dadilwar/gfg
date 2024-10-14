class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        #init variable for heap. Build min heap
        max_heap = []
        for pile in piles:
            heapq.heappush(max_heap, -pile)

        #perform operations k number of times
        for i in range(k):
            stone = -(heapq.heappop(max_heap))
            stone = stone - math.floor(stone / 2)
            heapq.heappush(max_heap, -stone)

        return -(sum([num for num in max_heap]))