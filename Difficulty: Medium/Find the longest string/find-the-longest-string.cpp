class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        unordered_map<string, int> mp;
        for(auto it: words)
            mp[it]++;
        
        sort(words.begin(), words.end(), [&](const auto& a, const auto& b){
            if(a.size() != b.size())
                return a.size() < b.size();
            else
                return a > b;
        });
        
        for(int i=words.size()-1; i>=0; i--){
            int l = words[i].size(), flag = true;
            string t = "";
            
            for(int k=0; k<l; k++){
                t += words[i][k];
                if(mp[t] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return words[i];
        }
        return "";
    }
};