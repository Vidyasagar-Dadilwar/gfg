#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n;
        cin >> n; 
        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        sort(arr.begin(), arr.end());

        long long total = 0; 
        for (int i = 0; i < n; i++) {
            int dis = max(0, arr[i] - i);
            total += dis;
        }
        cout << total << endl;
    }
    return 0;
}
