class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for(auto i: nums){
            if(i%3 == 0 && i%2 == 0){
                sum += i;
                cnt++;
            }
        }
        return (cnt == 0) ? 0 : sum/cnt;
    }
};