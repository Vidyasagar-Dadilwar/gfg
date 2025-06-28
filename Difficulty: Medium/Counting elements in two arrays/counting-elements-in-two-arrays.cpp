class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        int maxi = *max_element(b.begin(), b.end());
        maxi = max(maxi, *max_element(a.begin(), a.end()));
        vector<int> arr(maxi+1, 0);
        
        for(auto it: b)
            arr[it]++;
        
        for(int i=1; i<=maxi; i++)
            arr[i] += arr[i-1];
        
        vector<int> res;
        for(int it: a)
            res.push_back(arr[it]);
        
        return res;
    }
};