class Solution {
  public:
    int getLongestPrefix(string &s) {
        // code here
        int i = s.size() - 1,  j = 0, pos = i, cnt = 0;
        while(i>0 && i<s.size()){
            if(s[i] == s[j]){
                i++; j++;
            }
            else{
                j = 0;
                pos--;
                i = pos;
            }
        }
        return i == 0 ? -1 : pos;
    }
};