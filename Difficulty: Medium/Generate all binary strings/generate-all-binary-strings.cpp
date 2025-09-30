class Solution {
  public:
    void solve(int ind, int n, string &curr, vector<string>& ans){
        if(ind == n){
            ans.push_back(curr);
            return; 
        }
        curr.push_back('0');
        solve(ind+1, n, curr, ans);
        curr.pop_back();
        curr.push_back('1');
        solve(ind+1, n, curr, ans);
        curr.pop_back();
    }
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        string curr = "";
        solve(0, n, curr, ans);
        return ans;
    }
};