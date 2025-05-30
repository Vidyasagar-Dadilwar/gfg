class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        vector<int> ans;
        unordered_map<int, int> mp;
        for(auto it: arr)
            mp[it]++;
        
        for(auto it: mp){
            if(it.second > 1)
                ans.push_back(it.first);
        }
        return ans;
    }
};