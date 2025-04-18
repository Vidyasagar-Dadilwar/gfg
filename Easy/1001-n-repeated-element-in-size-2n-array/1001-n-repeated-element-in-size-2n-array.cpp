class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        map<int, int> mp;
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (auto it : mp) {
            if (it.second > 1) {
                ans = it.first;
            }
        }
        return ans;
    }
};