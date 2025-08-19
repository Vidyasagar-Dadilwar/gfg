class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1), suf(n);

        suf[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) 
            suf[i] = min(arr[i], suf[i+1]);

        for (int i = 0; i < n; i++) {
            int lo = i+1, hi = n-1, best = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (suf[mid] < arr[i]) {
                    best = mid;
                    lo = mid + 1; 
                } 
                else 
                    hi = mid - 1;
            }
            ans[i] = best;
        }
        return ans;
    }
};