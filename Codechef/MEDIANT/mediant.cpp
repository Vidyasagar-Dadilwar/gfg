#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSorted(vector<ll>& arr) {
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}

ll findMedian(vector<ll>& arr, int left, int right) {
    vector<ll> temp;
    for(int i = left; i <= right; i++) {
        temp.push_back(arr[i]);
    }
    sort(temp.begin(), temp.end());
    return temp[temp.size()/2];
}

vector<ll> performOperation(vector<ll>& arr, int left, int right) {
    ll median = findMedian(arr, left, right);
    vector<ll> result;
    bool deleted = false;
    
    for(int i = 0; i < arr.size(); i++) {
        if(i >= left && i <= right && arr[i] == median && !deleted) {
            deleted = true;
            continue;
        }
        result.push_back(arr[i]);
    }
    return result;
}

struct Operation {
    int left, right;
};

bool solve(vector<ll>& arr, vector<Operation>& ops, int maxOps = 50) {
    if(isSorted(arr)) return true;
    if(maxOps == 0) return false;
    if(arr.size() < 3) return false;
    
    int n = arr.size();
    for(int len = 3; len <= n; len += 2) {
        for(int left = 0; left + len - 1 < n; left++) {
            int right = left + len - 1;
            vector<ll> newArr = performOperation(arr, left, right);
            
            Operation op;
            op.left = left + 1;  
            op.right = right + 1;
            ops.push_back(op);
            
            if(solve(newArr, ops, maxOps - 1)) {
                return true;
            }
            
            ops.pop_back();
        }
    }
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<Operation> operations;
        bool possible = solve(arr, operations);
        
        if(!possible) {
            cout << -1 << "\n";
            continue;
        }
        
        cout << operations.size() << "\n";
        for(auto op : operations) {
            cout << op.left << " " << op.right << "\n";
        }
    }
    
    return 0;
}