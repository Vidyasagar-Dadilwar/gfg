from collections import defaultdict

class Solution:
    def countSubstr (self, s, k):
        # Code here
        def count_substrings_with_at_most_k_distinct(s, k):
            freq = defaultdict(int)
            left = 0
            count = 0
        
            for right in range(len(s)):
                freq[s[right]] += 1
        
                while len(freq) > k:
                    freq[s[left]] -= 1
                    if freq[s[left]] == 0:
                        del freq[s[left]]
                    left += 1
        
                # Number of substrings ending at right
                count += right - left + 1
        
            return count
        
        if k == 0:
            return 0
        return (count_substrings_with_at_most_k_distinct(s, k) -
                count_substrings_with_at_most_k_distinct(s, k - 1))