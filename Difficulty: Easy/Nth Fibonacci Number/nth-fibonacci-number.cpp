// User function Template for C++
class Solution {
  public:
    int fibo(int n){
        if(n == 0 || n == 1)
            return n;
        return fibo(n-1) + fibo(n-2);
    }
    int nthFibonacci(int n) {
        // code here
        return fibo(n);
    }
};