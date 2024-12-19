class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size(), 0);
        stack<pair<int, int>>st;
        for(int i=0; i<temp.size(); i++){
            while(!st.empty() && temp[i] > st.top().first){
                auto it = st.top();
                st.pop();
                res[it.second] = i - it.second;
            }
            st.push({temp[i], i});
        }
        return res;
    }
};