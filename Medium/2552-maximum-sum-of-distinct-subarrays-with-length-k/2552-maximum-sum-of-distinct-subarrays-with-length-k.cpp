class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l = 0, r = 0; 
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> freq; 
        while (r < nums.size()) {
            freq[nums[r]]++; 
            sum += nums[r]; 
            while (freq[nums[r]] > 1 || (r - l + 1) > k) {
                freq[nums[l]]--; 
                sum -= nums[l]; 
                l++; 
            }
            if (r - l + 1 == k) {
                maxSum = max(maxSum, sum);
            }
            r++; 
        }
        return maxSum; 
    }
};