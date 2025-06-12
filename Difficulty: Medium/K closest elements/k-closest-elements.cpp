class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int num : arr) {
            if (num == x) continue;
            int diff = abs(num - x);
            pq.push({diff, -num});  
        }

        vector<int> ans;

        while (k-- && !pq.empty()) {
            ans.push_back(-pq.top().second);  
            pq.pop();
        }

        return ans;
    }
};
