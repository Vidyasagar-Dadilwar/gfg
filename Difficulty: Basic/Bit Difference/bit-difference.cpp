class Solution {
  public:
    int countBitsFlip(int a, int b) {
        // code here
        int xorr = a^b;
        int cnt = 0;
        while(xorr){
            if(xorr&1)
                cnt++;
            xorr = xorr >> 1;
        }
        return cnt;
    }
};