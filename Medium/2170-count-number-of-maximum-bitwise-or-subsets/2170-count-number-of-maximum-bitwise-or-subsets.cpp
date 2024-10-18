class Solution {
public:
    int solve(int idx, int currOr, vector<int>&nums, int maxOr, vector<vector<int>>&temp){
        if(idx == nums.size()){
            if(currOr == maxOr){
                return 1;       // increase the count if subarray is found
            }
            return 0;
        }

        if(temp[idx][currOr] != -1)
            return temp[idx][currOr];
        
        int cntTkn = solve(idx+1, currOr|nums[idx], nums, maxOr, temp);
        int cntNtTkn = solve(idx+1, currOr, nums, maxOr, temp);

        return temp[idx][currOr] = cntTkn + cntNtTkn;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto i: nums){
            maxOr |= i;
        }
        int currOr = 0;
        int n = nums.size();
        vector<vector<int>>temp(n+1, vector<int>(maxOr+1, -1));

        return solve(0, currOr, nums, maxOr, temp);
    }
};