class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        int n = arr.size(), preSum = 0, maxLen = 0;

        unordered_map<int, int> mp;
        mp[0] = -1; 
    
        for (int i = 0; i < n; i++) {
            preSum += (arr[i] > k) ? 1 : -1;
    
            if (preSum > 0) 
                maxLen = i + 1;
            else if (mp.find(preSum - 1) != mp.end()) 
                maxLen = max(maxLen, i - mp[preSum - 1]);
    
            if (mp.find(preSum) == mp.end()) 
                mp[preSum] = i;
        }
        return maxLen;
    }
};