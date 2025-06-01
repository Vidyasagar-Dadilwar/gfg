
// User function template for C++

class Solution {
  public:
    int longestPrefixSuffix(string &str) {
        // Your code goes here
        int p=0, s=1, cnt=0, pos=1, n=str.size();
        while(p<n && s<n){
            if(str[p] == str[s]){
                cnt++; p++; s++;
            }
            else{
                cnt=0; pos++; s=pos; p=0;
            }
        }
        return cnt;
    }
};