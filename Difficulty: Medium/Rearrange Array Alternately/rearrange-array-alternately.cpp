class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        int l = 0, r = arr.size()-1;
        sort(arr.begin(), arr.end());
        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++){
            if(i%2==0)
                ans[i] = arr[r--];
            else
                ans[i] = arr[l++];
        }
        for(int i=0; i<arr.size(); i++)
            arr[i] = ans[i];
    }
};