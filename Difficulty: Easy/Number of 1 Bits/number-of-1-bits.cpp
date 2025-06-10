class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int cnt = 0;
        while(n){
            if(n&1)
                cnt++;
            n = n>>1;
        }
        return cnt;
    }
};