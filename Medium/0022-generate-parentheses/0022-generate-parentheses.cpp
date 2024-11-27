class Solution {
public:
    void solve(string curr, int n, int o, int c, vector<string> &res){
        if(o==n && c==n){
            res.push_back(curr);
            return;
        }
        if(o<n){
            solve(curr+"(", n, o+1, c, res);
        }
        if(c<o){
            solve(curr+")", n, o, c+1, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string curr="";
        int open=0,close=0;
        solve(curr,n,open,close,res);
        return res;
    }
};


