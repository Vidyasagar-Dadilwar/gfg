class Solution {
  public:
    void solve(string s, int ind, string curr, vector<string>& ans){
        if(ind == s.size())
            return;
        curr.push_back(s[ind]);
        ans.push_back(curr);
        solve(s, ind+1, curr, ans);
        curr.pop_back();
        solve(s, ind+1, curr, ans);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string> ans;
        solve(s, 0, "", ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};