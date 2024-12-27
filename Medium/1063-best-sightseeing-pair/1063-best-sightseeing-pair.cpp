class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxAns = 0;
        int maxii = values[0];
        for(int i=1; i<values.size(); i++){
            maxAns = max(maxAns, maxii + values[i] - i);
            maxii = max(maxii, values[i] + i);
        }
        return maxAns;
    }
};