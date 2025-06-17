class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for(int i=1; i<n; i++)
            pre[i] = pre[i-1] + arr[i];
        
        for(int i=0; i < n; i++){
            if(i > 0 && arr[i] == arr[i-1])
                continue;
            
            int prev = i == 0 ? 0 : pre[i-1];
            int t = upper_bound(arr.begin()+i, arr.end(),arr[i]+k)-arr.begin();
            int ttl = prev + (pre[n-1] - pre[t-1] - (n-t)*(arr[i]+k));
            ans = min(ans, ttl);
        }
        return ans;
    }
};
