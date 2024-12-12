class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        sort(gifts.begin(),gifts.end());

        for(auto i : gifts){
            ans+=i;
        }
        
        int high = gifts.size()-1;
        int low = gifts.size()-1;
        
        while(k>0){            
            if(gifts[low] >= gifts[high]){
                k--;
                ans-=gifts[low];
                gifts[low] = floor(sqrt(gifts[low]));
                ans+=gifts[low];
                low--;
            }
            else{
                k--;
                ans-=gifts[high];
                gifts[high] =  floor(sqrt(gifts[high]));
                ans+=gifts[high];
                high--;
            }         
            if(high < 0){
                high = gifts.size()-1;
            }
            if(gifts[high] < gifts[gifts.size()-1]){
                high = gifts.size()-1;
            }
            if(low < 0){
                low = gifts.size()-1;
            }
        }        
        return ans;
    }
};