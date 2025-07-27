class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        vector<int> rows, cols;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 0){
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        
        for(auto it: rows){
            for(int j=0; j<mat[0].size(); j++){
                mat[it][j] = 0;
            }
        }
        
        for(auto it: cols){
            for(int i=0; i<mat.size(); i++){
                mat[i][it] = 0;
            }
        }
    }
};