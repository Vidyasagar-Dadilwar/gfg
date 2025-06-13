class Solution {
  public:
    int solve(vector<int> arr, int m){
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            cnt += ceil(arr[i]*1.0/m);
        }
        return cnt;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int l = 1, h = *max_element(arr.begin(), arr.end());
        int ans = h;
        while(l <= h){
            int m = l + (h - l)/2;
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