class Solution {
public:
    int countAtMostK(string& s, int k) {
        int n = s.size(), l = 0, r = 0, cnt = 0, unique = 0;
        vector<int> freq(256, 0); 
        while (r < n) {
            if (freq[s[r]] == 0) unique++;
            freq[s[r]]++;

            while (unique > k) {
                freq[s[l]]--;
                if (freq[s[l]] == 0) unique--;
                l++;
            }

            cnt += r - l + 1;
            r++;
        }

        return cnt;
    }

    int countSubstr(string& s, int k) {
        if (k == 0) return 0;
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }
};