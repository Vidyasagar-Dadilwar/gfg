class Solution {
public:
    struct CustomComparator {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if (a.second == b.second)
                return a.first < b.first;  
            return a.second < b.second;    
        }
    };

    vector<int> topKFreq(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for (int num : arr)
            freq[num]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparator> pq;
        for (auto& p : freq)
            pq.push({p.first, p.second});

        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};