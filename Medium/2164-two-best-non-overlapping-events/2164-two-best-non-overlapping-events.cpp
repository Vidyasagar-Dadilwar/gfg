class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>&a, const vector<int>&b){
            return a[1]<b[1];
        });
        int n=events.size();
        vector<int>max_value(n, 0);
        int maxValue=0;
        for(int i=0; i<n; i++){
            max_value[i] = max(events[i][2], (i>0 ?  max_value[i - 1] : 0));
        }
        for (int i = 0; i < n; ++i) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];

            int idx = upper_bound(events.begin(), events.end(), vector<int>{0, start - 1, 0}, 
                                  [](const vector<int>& a, const vector<int>& b) {
                                      return a[1] < b[1];
                                  }) - events.begin() - 1;

            int tmp = (idx >= 0 ? max_value[idx] : 0);
            maxValue = max(maxValue, value + tmp);
        }
        return maxValue;
    }
};