class Solution {
  public:
    int solve(int n, int x, int y, int z, vector<int>& dp){
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MIN;
        if(dp[n] != -1)
            return dp[n];
        
        int a = solve(n - x, x, y, z, dp);
        int b = solve(n - y, x, y, z, dp);
        int c = solve(n - z, x, y, z, dp);
        
        int maxCuts = max({a, b, c});
        if (maxCuts == INT_MIN)
            return dp[n] = INT_MIN;
        return dp[n] = 1 + maxCuts;
    }

    int maximizeTheCuts(int n, int x, int y, int z) {
        vector<int> dp(n + 1, -1);
        int ans = solve(n, x, y, z, dp);
        return ans < 0 ? 0 : ans;
    }
};