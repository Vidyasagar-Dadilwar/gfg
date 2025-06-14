
class Solution {
  public:
    int tribo(int n, vector<int>& dp){
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = tribo(n-3, dp) + tribo(n-1, dp) + tribo(n-2, dp);
    }
    int nthTribonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return tribo(n, dp);
    }
};
