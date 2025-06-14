#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    const int MOD = 1e9 + 7;

    long long solve(int n, vector<long long>& dp){
        if(n == 0)
            return 2;
        if(n == 1)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = (solve(n-1, dp) % MOD + solve(n-2, dp) % MOD) % MOD;
    }

    long long lucas(int n) {
        vector<long long> dp(n+1, -1);
        return solve(n, dp);
    }
};