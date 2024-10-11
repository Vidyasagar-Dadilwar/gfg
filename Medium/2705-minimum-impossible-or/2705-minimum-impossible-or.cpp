class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int pow = 0;
        for(auto x: nums){
            if((x&(x-1))==0){
                pow |= x;
            }
        }
        int mini = 1;
        while((pow & mini) > 0){
            mini = (mini << 1);
        }
        return mini;
    }
};