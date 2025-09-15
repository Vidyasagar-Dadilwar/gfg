class Solution {
  public:
    bool stringStack(string &pat, string &tar) {
        // code here
        int i=pat.size()-1, j=tar.size()-1;
        while(i>=0 && j>=0){
            if(pat[i] == tar[j])
                i--, j--;
            else
                i -= 2;
            if(j < 0)
                return true;
        }
        return false;
    }
};