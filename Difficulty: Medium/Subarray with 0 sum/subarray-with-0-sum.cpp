class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int> ans;
        int prefix=0;
        for(auto it: arr){
            prefix += it;
            if(prefix == 0 || ans.count(prefix) > 0)
                return true;
            ans.insert(prefix);
        }
        return false;
    }
};