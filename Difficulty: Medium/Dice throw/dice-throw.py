class Solution:
    def noOfWays(self, m,n,x):
        # code here
        def solve(m, n, x, dp):
            if(n == 0):
                return x == 0
            
            if(x < 0):
                return 0;
                
            if(dp[n][x] != -1):
                return dp[n][x]
                
            cnt = 0
            for i in range(1, m+1):
                cnt += solve(m, n-1, x-i, dp)
            
            dp[n][x] = cnt
            return dp[n][x]
        
        dp = [[-1 for _ in range(x + 1)] for _ in range(n + 1)]
        return solve(m, n, x, dp)