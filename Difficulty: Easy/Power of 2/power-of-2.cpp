// User function Template for C++

class Solution {
  public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n) {
        // code here
        if(n == 0)  return false;
        if(n == 1)  return true;
        int cnt = 0;
        while(n){
            if(n&1)
                cnt++;
            n = n>>1;
            if(cnt > 1)
                break;
        }
        return cnt == 1;
    }
};