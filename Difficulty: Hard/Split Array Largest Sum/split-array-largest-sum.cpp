class Solution {
  public:
    int solve(vector<int>arr, int k, int m){
        int s = 0;
        for(int i: arr){
            s += i;
            if(s > m){
                k--;
                s = i;
            }
        }
        return (k>0 && s<=m);
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int s = *max_element(arr.begin(), arr.end());
        int e = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(solve(arr, k, m)){
                ans = m;
                e = m-1;
            }
            else
                s = m+1;
        }
        return ans;
    }
};