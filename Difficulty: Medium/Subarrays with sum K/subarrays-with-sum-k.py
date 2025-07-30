from collections import defaultdict

class Solution:
    def cntSubarrays(self, arr, k):
        cnt = 0
        sum_ = 0
        mp = defaultdict(int)

        for num in arr:
            sum_ += num

            if sum_ == k:
                cnt += 1

            if (sum_ - k) in mp:
                cnt += mp[sum_ - k]

            mp[sum_] += 1

        return cnt