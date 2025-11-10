class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        // code here
        int n = arr.size();
        int buy = -arr[0], sell = 0, skip = 0;   
        
        for (int i=1; i<n; i++) {
            int price = arr[i];
            
            int prvBuy = buy;
            int prvSell = sell;
            int prvSkip = skip;
            
            buy = max(prvBuy, prvSkip-price);  
            sell = prvBuy+price;    
            skip = max(prvSkip, prvSell);  
        }
        
        return max(sell, skip);
    }
};