class Solution(object):
    def kthSmallest(self, m, n, k):
        def solve(x):
            cnt = 0
            for i in range(1, m + 1):
                cnt += min(x // i, n)
            return cnt

        l, r = 1, m * n
        while l < r:
            mid = (l + r) // 2
            if solve(mid) >= k:
                r = mid
            else:
                l = mid + 1
        return l
