#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int p, s;
    cin>>p>>s;
    vector<pair<int, int>>diff;
    for(int i=0; i<p; i++){
        vector<int> sp(s), con(s);
        for(int j=0; j<s; j++){
            cin>>sp[j];
        }
        for(int j=0; j<s; j++){
            cin>>con[j];
        }
        vector<pair<int, int>> subtasks(s);
        for (int j = 0; j < s; j++) {
            subtasks[j] = {sp[j], con[j]};
        }
        sort(subtasks.begin(), subtasks.end());
        int n = 0;
        for (int j = 0; j < s - 1; j++) {
            if (subtasks[j].second > subtasks[j + 1].second) {
                n++;
            }
        }
        diff.push_back({n, i + 1});
    }
    sort(diff.begin(), diff.end());
    for (const auto& problem : diff) {
        cout << problem.second << endl;
    }
}
