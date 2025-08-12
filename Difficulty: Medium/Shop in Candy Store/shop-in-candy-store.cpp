class Solution {
public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        int n = prices.size(), minCost = 0;
        int i = 0, j = n - 1;
        while (i <= j) {
            minCost += prices[i++];
            j -= k; 
        }
        int maxCost = 0;
        i = 0; j = n - 1;
        while (i <= j) {
            maxCost += prices[j--];
            i += k;
        }
        return {minCost, maxCost};
    }
};