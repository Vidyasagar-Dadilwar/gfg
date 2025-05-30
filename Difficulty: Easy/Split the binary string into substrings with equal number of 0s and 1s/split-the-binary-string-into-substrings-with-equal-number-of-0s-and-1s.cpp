class Solution {
  public:
    int maxSubStr(string str) {
        // Write your code here
        int ans = 0, z=0;
        for(auto it: str){
            if(it == '0')
                z--;
            else
                z++;
            if(z == 0)
                ans++;
        }
        return (z == 0) ? ans : -1;
    }
};
