class Solution {
  public:
    int findMaxValue(vector<vector<int>>& mat, int N) {
        vector<vector<int>> arr(N, vector<int>(N, 0));
        int result = INT_MIN;

        int maxVal = mat[N-1][N-1];
        arr[N-1][N-1] = maxVal;
        for(int j = N-2; j >= 0; j--) {
            maxVal = max(maxVal, mat[N-1][j]);
            arr[N-1][j] = maxVal;
        }

        maxVal = mat[N-1][N-1];
        for(int i = N-2; i >= 0; i--) {
            maxVal = max(maxVal, mat[i][N-1]);
            arr[i][N-1] = maxVal;
        }

        for(int i = N-2; i >= 0; i--) {
            for(int j = N-2; j >= 0; j--) {
                result = max(result, arr[i+1][j+1] - mat[i][j]);

                arr[i][j] = max({
                    mat[i][j],
                    arr[i+1][j],
                    arr[i][j+1]
                });
            }
        }

        return result;
    }
};