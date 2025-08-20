class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size(), l = 0, h = (n*m) - 1;;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            int midVal = mat[mid / m][mid % m];
            int lVal = mat[l / m][l % m];
            int hVal = mat[h / m][h % m];

            if (midVal == x) return true;
            if (lVal <= midVal) {
                if (lVal <= x && x < midVal) 
                    h = mid - 1;
                else 
                    l = mid + 1;
            }
            else {
                if (midVal < x && x <= hVal) 
                    l = mid + 1;
                else 
                    h = mid - 1;
            }
        }
        return false;
    }
};