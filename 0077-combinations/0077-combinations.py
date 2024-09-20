class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        import itertools
        nums = list(range(1, n + 1))
        return list(itertools.combinations(nums, k))