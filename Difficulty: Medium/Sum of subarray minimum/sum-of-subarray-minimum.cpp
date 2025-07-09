class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> prev(n), next(n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            prev[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();
        
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            next[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = (result + (long long)arr[i] * prev[i] * next[i]) % MOD;
        }
        return result;
    }
};
