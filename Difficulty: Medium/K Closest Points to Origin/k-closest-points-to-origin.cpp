class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // code here
        priority_queue<pair<double, int>> pq;
        int i = 0;
        for(auto it: points){
            double d = sqrt(it[0]*it[0] + it[1]*it[1]);
            pq.push({-1*d, i});
            i++;
        }
        
        vector<vector<int>> ans;
        while(k--){
            auto it = pq.top();
            pq.pop();
            ans.push_back(points[it.second]);
        }
        return ans;
    }
};