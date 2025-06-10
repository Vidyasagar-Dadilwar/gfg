class Solution {
  public:
    int findPosition(int n) {
        // code here
        int cnt = 0, ind = -1, i = 1;
        while(n){
            if(n&1){
                cnt++;
                ind = i;
            }
            n = n >> 1;
            i++;
            if(cnt > 1)
                return -1;
        }
        return (cnt == 0) ? -1 : ind;
    }
};