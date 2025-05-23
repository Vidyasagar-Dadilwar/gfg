class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int sum = 0, maxi = INT_MIN;
        for(int i=0; i<arr.size(); i++){
            if(sum < 0){
                sum = 0;
            }
            sum += arr[i];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};