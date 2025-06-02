class Solution {
  public:
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
        int n = grid.size(), m = grid[0].size();

        if(i >= n || j >= m || grid[i][j] == 1)
            return 0;

        if(i == n-1 && j == m-1)
            return 1;

        if(dp[i][j] != -1)
            return dp[i][j];

        int down = dfs(grid, i+1, j, dp);
        int right = dfs(grid, i, j+1, dp);

        dp[i][j] = down + right;
        return dp[i][j];
    }

    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, -1));
        return dfs(grid, 0, 0, dp);
    }
};