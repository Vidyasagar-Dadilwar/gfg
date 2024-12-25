#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    vector<pair<int, vector<int>>> ttt;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        ttt.emplace_back(N, A);
    }
    vector<int> res;
    for (auto &it : ttt) {
        int N = it.first;
        vector<int> &A = it.second;
        unordered_map<int, vector<int>> tmp;

        for (int i = 0; i < N; ++i) {
            tmp[A[i]].push_back(i + 1);
        }

        int tPenalty = 0;
        for (auto &[key, indices] : tmp) {
            tPenalty += *max_element(indices.begin(), indices.end());
        }

        res.push_back(tPenalty);
    }

    for (int result : res) {
        cout << result << endl;
    }
    return 0;
}
