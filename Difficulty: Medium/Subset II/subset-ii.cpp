class Solution {
public:
    void solve(vector<int>& nums, int ind, vector<int>& ans, vector<vector<int>>& res){
        if(ind == nums.size()){
            if (find(res.begin(), res.end(), ans) == res.end()){
                res.push_back(ans);
            }
            return ;
        }    
        ans.push_back(nums[ind]);
        solve(nums, ind+1, ans, res);
        ans.pop_back();
        solve(nums, ind+1, ans, res);
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        solve(nums, 0, ans, res);
        return res;
    }
};