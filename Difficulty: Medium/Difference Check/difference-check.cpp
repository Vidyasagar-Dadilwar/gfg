class Solution {
  public:
    int minDifference(vector<string> &arr) {
        vector<int> ans;
        for(const string& time : arr) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            int s = stoi(time.substr(6, 2));
            
            int total = h * 3600 + m * 60 + s;
            ans.push_back(total);
        }
        
        sort(ans.begin(), ans.end());
        int mini = INT_MAX;
        
        for(int i = 1; i < ans.size(); i++) 
            mini = min(mini, ans[i] - ans[i-1]);
        
        int tmp = (ans[0] + 24 * 3600) - ans.back();
        mini = min(mini, tmp);
        
        return mini;
    }
};