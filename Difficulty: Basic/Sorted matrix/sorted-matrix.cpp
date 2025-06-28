// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
        // code here
        vector<int> arr;
        int n = Mat.size(), m = Mat[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                arr.push_back(Mat[i][j]);
        sort(arr.begin(), arr.end());
        int k = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                Mat[i][j] = arr[k++];
        return Mat;
    }
};