class Solution {
  public:
    long long lcm_fun(long long a, long long b) {
        return a / __gcd(a, b) * b;
    }

    int lcmTriplets(int n) {
        if(n < 3)
            return n;
        
        if(n%2 == 0)
            return max(lcm_fun(n, lcm_fun(n-1, n-3)), lcm_fun(n-1, lcm_fun(n-2, n-3))); 
        else
            return lcm_fun(n, lcm_fun(n-1, n-2));
    }
};
