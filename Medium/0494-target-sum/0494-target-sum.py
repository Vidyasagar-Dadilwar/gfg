class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        @cache
        def solve(ind: int, sum: int) -> int:
            if ind == len(nums):
                return 1 if sum == target else 0
            return solve(ind + 1, sum + nums[ind]) + solve(ind + 1, sum - nums[ind])
        
        return solve(0, 0)