class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int>&temp, vector<int>&candidates, int ind, int currSum, int target){
        if(currSum > target){
            return;
        }
        if(currSum == target){
            ans.push_back(temp);
            return;
        }
        for(int i = ind; i < candidates.size(); i++){
            if(i > ind && candidates[i] == candidates[i-1]) 
                continue;
            
            currSum += candidates[i];
            temp.push_back(candidates[i]);
            
            solve(ans, temp, candidates, i+1, currSum, target);
            
            currSum -= candidates[i];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        solve(ans, temp, candidates, 0, 0, target);
        return ans;
    }
};