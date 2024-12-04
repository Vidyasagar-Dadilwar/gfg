#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        ll X;
        cin >> N >> X;

        vector<pair<ll, ll>> coins(N);
        for (int i = 0; i < N; ++i) {
            cin >> coins[i].first;
        }
        for (int i = 0; i < N; ++i) {
            cin >> coins[i].second; 
        }

        sort(coins.rbegin(), coins.rend());

        ll rem = X;
        int ans = 0;
        for (auto &coin : coins) {
            if (rem <= 0) break;

            ll value = coin.first;
            ll count = coin.second;

            ll temp = min(count, rem / value + (rem % value != 0));
            if (temp > 0) {
                rem -= temp * value;
                ++ans;
            }
        }

        if (rem > 0) {
            cout << -1 << "\n"; 
        } 
        else {
            cout << ans << "\n"; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
