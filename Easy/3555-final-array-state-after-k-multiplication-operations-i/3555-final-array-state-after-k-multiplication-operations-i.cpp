class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        while(k--){
            auto [val, i] = pq.top();
            pq.pop();
            pq.push({val * multiplier, i});
        }
        vector<int> res(nums.size());
        while (!pq.empty()) {
            auto [val, i] = pq.top();
            pq.pop();
            res[i] = val; 
        }
        return res;
    }
};