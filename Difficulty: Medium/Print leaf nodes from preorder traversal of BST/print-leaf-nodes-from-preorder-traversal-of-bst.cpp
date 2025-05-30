class Solution {
  public:
    vector<int> leafNodes(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        st.push(arr[0]);
        vector<int> ans;
        
        for(int i=1; i<n; i++){
            if(arr[i] < st.top())
                st.push(arr[i]);
            else{
                int sz = st.size();
                int t = st.top();
                while(!st.empty() && arr[i] > st.top())
                    st.pop();
                st.push(arr[i]);
                if(sz > st.size())
                    ans.push_back(t);
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};