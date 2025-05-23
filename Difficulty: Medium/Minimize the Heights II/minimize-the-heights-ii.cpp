// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size(), mini, maxi;
        sort(arr.begin(), arr.end());
        int ans = arr[n-1] - arr[0];
        int s = arr[0] + k, l = arr[n-1] - k;
        
        for(int i=0; i<n-1; i++){
            maxi = max(l, arr[i] + k);
            mini = min(s, arr[i+1] - k);
            
            if(mini < 0)
                continue;
            
            ans = min(ans, maxi - mini);
        }
        return ans;
    }
};