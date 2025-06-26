class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        vector<int> preSum(arr.size(), 0);
        preSum[0] = arr[0];
        for(int i=1; i<arr.size(); i++)
            preSum[i] = preSum[i-1]+arr[i];
            
        for(int i=0; i<arr.size(); i++){
            for(int j=i; j<arr.size(); j++){
                int sum = preSum[j] - (i > 0 ? preSum[i - 1] : 0);
                if (sum == target) {
                    return {i+1, j+1};
                }
            }
        }
        return {-1};
    }
};