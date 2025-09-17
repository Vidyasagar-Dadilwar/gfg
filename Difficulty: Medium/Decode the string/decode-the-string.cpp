class Solution {
public:
    string decodedString(string &s) {
        stack<pair<string, int>> st;
        int num = 0;
        string curr = "";
        
        for (auto ch : s) {
            if (isdigit(ch)) 
                num = num * 10 + (ch - '0'); 
            else if (ch == '[') {
                st.push({curr, num});
                curr = "";
                num = 0;
            } 
            else if (ch == ']') {
                auto [prev, t] = st.top();
                st.pop();
                
                string temp = "";
                while (t--) {
                    temp += curr; 
                }
                curr = prev + temp;
            } 
            else 
                curr += ch;
        }
        return curr;
    }
};