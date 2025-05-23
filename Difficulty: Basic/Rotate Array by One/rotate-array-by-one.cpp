// User function Template for C++

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        reverse(arr.begin(), arr.begin() + arr.size() - 1);
        reverse(arr.begin(), arr.end());
    }
};