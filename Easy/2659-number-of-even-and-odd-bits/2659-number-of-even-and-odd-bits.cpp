class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int>ans;
        while(n){
            ans.push_back(n%2);
            n/=2;
        }
        int even=0, odd=0;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]==1){
                if(i%2==0){
                    even++;
                }
                else{
                    odd++;
                }
            }
        }
        return {even, odd};
    }
};