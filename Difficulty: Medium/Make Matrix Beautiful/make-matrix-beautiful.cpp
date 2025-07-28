class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        vector<int>row(n,0);
        vector<int>col(n,0);
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }
        
        int mx = 0;
        for(int i = 0; i < n; i++){
            mx = max(mx, max(row[i], col[i]));
        }
        
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans +=(mx-row[i]);
        }
        
        return ans;
    }
};