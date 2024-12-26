class Solution {
public:
    int solve(vector<int> &nums, int ind, int sum, int target, unordered_map<string, int> &memo) {
        string key = to_string(ind) + "," + to_string(sum);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        if (ind == nums.size()) {
            return sum == target ? 1 : 0;
        }
        memo[key] = solve(nums, ind + 1, sum + nums[ind], target, memo) + solve(nums, ind + 1, sum - nums[ind], target, memo);
        return memo[key];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> memo;
        return solve(nums, 0, 0, target, memo);
    }
};
