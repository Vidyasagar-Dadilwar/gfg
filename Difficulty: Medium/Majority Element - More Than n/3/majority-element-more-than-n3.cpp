class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int num : arr) {
            mp[num]++;
        }

        vector<int> result;
        int n = arr.size();
        for (auto& it : mp) {
            if (it.second > n / 3) {
                result.push_back(it.first);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};