class Solution {
  public:
    void solve(string& s, int target, int ind, long long curr, long long prev, string st, vector<string>& ans){
        if(ind == s.size()){
            if(curr == target)
                ans.push_back(st);
            return;
        }
        
        for(int i=ind; i<s.size(); i++){
            if(i != ind && s[ind] == '0') break;
            string tmp = s.substr(ind, i-ind+1);
            long long val = stoll(tmp);
            if(ind == 0)
                solve(s, target, i+1, val, val, tmp,ans);
            else{
                solve(s, target, i + 1, curr + val, val, st + "+" + tmp, ans);
                solve(s, target, i + 1, curr - val, -val, st + "-" + tmp, ans);
                solve(s, target, i + 1, curr - prev + prev * val, prev * val, st + "*" + tmp, ans);
            }
        }
    }
    vector<string> findExpr(string &s, int target) {
        // code here
        vector<string> ans;
        solve(s, target, 0, 0, 0, "", ans);
        return ans;
    }
};