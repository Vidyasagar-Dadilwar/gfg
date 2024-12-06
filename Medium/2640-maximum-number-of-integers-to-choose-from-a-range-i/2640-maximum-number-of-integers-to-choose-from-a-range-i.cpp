class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        set<int> st;
        for (auto i : banned) {
            if (i <= n) { 
                st.insert(i);
            }
        }
        int sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (st.find(i) == st.end()) { 
                sum += i;
                if (sum <= maxSum) {
                    cnt++;
                } else {
                    break;
                }
            }
        }
        return cnt; 
    }
};