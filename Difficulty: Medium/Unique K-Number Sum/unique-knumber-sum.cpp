class Solution {
  public:
    void solve(int start, int sum, int tar, int size, vector<int>& tmp, vector<vector<int>>& ans){
        if(tmp.size() == size){
            if(sum == tar)
                ans.push_back(tmp);
            return;
        }
        for(int i=start; i<=9; i++){
            if(sum > tar)
                break;
            sum += i;
            tmp.push_back(i);
            solve(i+1, sum, tar, size, tmp, ans);
            sum -= i;
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(1, 0, n, k, tmp, ans);
        return ans;
    }
};