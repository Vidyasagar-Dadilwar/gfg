#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int n, long long l, long long r) {
    long long prod = 1; // To hold the product
    bool outOfBounds = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int xorr = arr[i] ^ arr[j]; 
            prod *= xorr;
            if (prod == 0 && prod>=l && prod<=r) {
                cout << "YES\n";
                return;
            }
            if (prod > r) {
                outOfBounds = true;
                break;
            }
        }
        if (outOfBounds) break;
    }

    if (prod >= l && prod <= r)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        solve(arr, n, l, r);
    }
    return 0;
}
