class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>nans(piles.begin(),piles.end());
        for(int i=0;i<k;i++){
            int a = nans.top();
            nans.pop();
            a = a - (a/2);
            nans.push(a);
        }
        int result = 0;
        for(int i=0;i<piles.size();i++){
            int a= nans.top();
            result = result + a;
            nans.pop();
        }
        return result;
    }
};