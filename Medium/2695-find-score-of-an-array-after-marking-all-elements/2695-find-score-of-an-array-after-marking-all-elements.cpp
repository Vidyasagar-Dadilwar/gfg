class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.push_back({nums[i], i});
        }
        sort(elements.begin(), elements.end());
        
        vector<bool> marked(n, false);

        for (auto& [val, i] : elements) {
            if (!marked[i]) {
                score += val;    
                marked[i] = true; 
                if (i > 0) 
                    marked[i - 1] = true; 
                if (i < n - 1) 
                    marked[i + 1] = true; 
            }
        }
        return score;
    }
};