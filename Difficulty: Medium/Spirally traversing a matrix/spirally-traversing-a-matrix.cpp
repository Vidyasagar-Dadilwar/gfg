class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int t=0, l=0, r=mat[0].size()-1, b=mat.size()-1;
        int i=0;
        vector<int> ans;
        while(l<=r && t<=b){
            for(int i=l; i<=r; i++)
                ans.push_back(mat[t][i]);
            t++;
            for(int i=t; i<=b; i++)
                ans.push_back(mat[i][r]);
            r--;
            if(t<=b){
                for(int i=r; i>=l; i--)
                    ans.push_back(mat[b][i]);
                b--;
            }
            if(l<=r){
                for(int i=b; i>=t; i--)
                    ans.push_back(mat[i][l]);
                l++;
            }
        }
        return ans;
    }
};