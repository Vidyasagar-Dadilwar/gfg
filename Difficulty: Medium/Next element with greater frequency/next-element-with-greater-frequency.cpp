class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        if (arr.empty()) 
            return {}; 
        
        unordered_map<int, int> mp;
        for (auto it : arr) 
            mp[it]++;
        
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && mp[arr[i]] >= mp[st.top()])
                st.pop();
            if (!st.empty())
                ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};