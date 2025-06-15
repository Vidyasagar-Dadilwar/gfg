class Solution {
  public:
    int solve(vector<int>& arr, int m){
        int sum = 0;
        for(auto it: arr){
            sum += ceil(it*1.0/m);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int l = 1, h = *max_element(arr.begin(), arr.end()), ans = 0;
        while(l<=h){
            int m = l + (h - l) / 2;
            if(solve(arr, m) <= k){
                h = m - 1;
                ans = m;
            }
            else
                l = m + 1;
        }
        return ans;
    }
};
