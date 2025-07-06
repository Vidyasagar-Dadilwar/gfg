#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());

        int n = a.size(), m = b.size();

        // Max heap using pair<sum, pair<i, j>>
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        set<pair<int, int>> visited;

        maxHeap.push({a[0] + b[0], {0, 0}});
        visited.insert({0, 0});

        vector<int> ans;

        while (k-- && !maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();

            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            ans.push_back(sum);

            if (i + 1 < n && !visited.count({i + 1, j})) {
                maxHeap.push({a[i + 1] + b[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            if (j + 1 < m && !visited.count({i, j + 1})) {
                maxHeap.push({a[i] + b[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        return ans;
    }
};