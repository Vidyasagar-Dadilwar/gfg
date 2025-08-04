class Solution {
  public:
    int maxRectSum(vector<vector<int>> &mat) {
        int ans = INT_MIN, n = mat.size(), m = mat[0].size();
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++)
                    temp[k] += mat[j][k];

                int maxi = INT_MIN, curr = 0;
                for(int k=0;k<m;k++){
                    curr += temp[k];
                    maxi = max(maxi,curr);
                    if(curr < 0)
                        curr = 0;
                }
                ans = max(ans,maxi);
            }
        }
        return ans;
    }
};