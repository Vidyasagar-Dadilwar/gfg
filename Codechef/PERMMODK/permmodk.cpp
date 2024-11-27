#include <bits/stdc++.h>
using namespace std;

void solve(int N, int K) {
    if (K == 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = i + 1;
    }
    
    rotate(P.begin(), P.begin() + (K - 1), P.end());
    
    for (int i = 0; i < N; ++i) {
        cout << P[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, K;
        cin >> N >> K;
        solve(N, K);
    }
    
    return 0;
}
