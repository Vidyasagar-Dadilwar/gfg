// User function Template for C++

class Solution {
  public:
    vector<vector<int>> res; 
    void solve(vector<int> arr, int ind, vector<int>& ans){
        if(ind == arr.size()){
            // print the subset and return
            res.push_back(ans);
            return;
        }
        ans.push_back(arr[ind]);
        solve(arr, ind+1, ans);
        ans.pop_back();
        solve(arr, ind+1, ans);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int> ans;
        solve(arr, 0, ans);
        sort(res.begin(), res.end());
        return res;
    }
};