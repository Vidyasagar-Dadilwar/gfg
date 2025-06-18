class Solution {
  public:
    bool palindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    void solve(string &s, int ind, vector<string>& tmp, vector<vector<string>>& ans){
        if(ind >= s.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(palindrome(s, ind, i)){
                tmp.push_back(s.substr(ind, i-ind+1));
                solve(s, i+1, tmp, ans);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> tmp;
        solve(s, 0, tmp, ans);
        return ans;
    }
};