class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        vector<int> freq(26, 0);
        for(auto c: s){
            freq[c - 'a']++;
        }
        int maxi = 25, i = maxi, limit;
        while(i>=0){
            if(freq[i]){
                if(i == maxi){
                    limit = repeatLimit;
                }
                else{
                    limit = 1;
                }
                while(limit--){
                    ans += (char)('a' + i);
                    if(--freq[i] == 0){
                        break;
                    }
                }
                if(i == maxi){
                    if(freq[i] == 0){
                        i = --maxi;
                    }
                    else{
                        i--;
                    }
                }
                else{
                    i = maxi;
                }
            }
            else{
                if(i == maxi){
                    i = --maxi;
                }
                else{
                    i--;
                }
            }
        }
        return ans;
    }
};