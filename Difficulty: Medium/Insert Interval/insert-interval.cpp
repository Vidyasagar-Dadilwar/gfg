class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            int s1 = intervals[i][0], e1 = intervals[i][1];
            int e2 = ans.back()[1];
            
            if(e2 < s1)
                ans.push_back(intervals[i]);
            else
                ans.back()[1] = max(e2, e1);
        }
        return ans;
    }
};