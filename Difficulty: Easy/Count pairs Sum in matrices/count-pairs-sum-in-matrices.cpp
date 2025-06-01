class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        // code here
        int cnt = 0, n = mat1.size();
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[mat1[i][j]] = {i, j};
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mp.find(x-mat2[i][j]) != mp.end())
                    cnt++;
            }
        }
        return cnt;
    }
};