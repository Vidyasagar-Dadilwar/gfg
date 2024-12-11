#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        string s, t; 
        cin >> s >> t;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                ans++;
            }
        }

        if (ans % 2 == 0) {
            cout << "YES\n";
        } 
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
