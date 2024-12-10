class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        for(int i=0; i<s.size(); i++){
            int subStrLen = 0;
            char currChar = s[i];
            for(int j=i; j<s.size(); j++){
                if(s[j] == currChar){
                    subStrLen++;
                    mp[{currChar, subStrLen}]++;
                }
                else{
                    break;
                }
            }
        }
        int ans = 0;
        for(auto it: mp){
            if(it.second >= 3 && it.first.second > ans){
                ans = it.first.second;
            }
        }
        return ans == 0 ? -1 : ans;
    }
};