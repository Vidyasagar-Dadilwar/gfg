class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int ans = 0;
        for(int i=0; i<arr.size(); i++)
            ans += arr[i] * (i+1) * (arr.size()-i);
        return ans;
    }
};