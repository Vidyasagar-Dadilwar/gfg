// User function Template for C++

class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int solve(int n){
        if(n == 0)
            return 0;
        int x=0;
        while((1<<x) <= n)
            x++;
        x--;
        int a = x*(1<<(x-1)) , b = n-(1<<x)+1, c = solve(n-(1<<x));
        
        return a+b+c;
    }
    int countSetBits(int n) {
        // Your logic here
        if(n & n-1)
            return solve(n);
        return solve(n-1)+1;
    }
};
