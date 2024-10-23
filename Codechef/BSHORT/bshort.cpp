#include <bits/stdc++.h>
using namespace std;

int cOnes(const string& s, int start, int end) {
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(s[i] == '1') count++;
    }
    return count;
}

string rmvCh(string s, int start, int end, bool rZeros) {
    string result;
    for(int i = 0; i < start; i++) {
        result += s[i];
    }
    
    for(int i = start; i <= end; i++) {
        if(rZeros) {
            if(s[i] == '1') result += s[i];
        } else {
            if(s[i] == '0') result += s[i];
        }
    }
    for(int i = end + 1; i < s.length(); i++) {
        result += s[i];
    }
    return result;
}

int solve(string s) {
    int n = s.length();
    if(n == 0) return 0;
    
    int minLen = n;
    queue<string> q;
    set<string> seen;
    q.push(s);
    seen.insert(s);
    
    while(!q.empty()) {
        string curr = q.front();
        q.pop();
        
        minLen = min(minLen, (int)curr.length());
        for(int i = 0; i < curr.length(); i++) {
            for(int j = i; j < curr.length(); j++) {
                int ones = cOnes(curr, i, j);
                bool rZeros = (ones % 2 == 1);  
                
                string next = rmvCh(curr, i, j, rZeros);
                if(seen.find(next) == seen.end()) {
                    seen.insert(next);
                    q.push(next);
                }
            }
        }
    }
    
    return minLen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    
    return 0;
}