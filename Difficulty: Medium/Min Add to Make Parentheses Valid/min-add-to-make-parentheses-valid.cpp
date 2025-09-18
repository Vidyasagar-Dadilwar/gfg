class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        string p;
        for(char it: s){
            if(!p.empty() && it == ')' && p.back() == '(')
                p.pop_back();
            else
                p.push_back(it);
        }
        return p.size();
    }
};