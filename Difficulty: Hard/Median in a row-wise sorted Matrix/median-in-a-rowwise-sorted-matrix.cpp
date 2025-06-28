// User function template for C++

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int> ans;
        int n = mat.size(), m = mat[0].size(); 
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ans.push_back(mat[i][j]);
        sort(ans.begin(), ans.end());
        return ans[n*m/2];
    }
};
