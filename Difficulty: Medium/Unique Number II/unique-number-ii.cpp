//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int xorr = 0;
        for(auto it: arr)
            xorr ^= it;
        xorr &= -xorr;
        vector<int> ans(2, 0);
        for(auto it: arr){
            if((it & xorr) == 0)
                ans[0] ^= it;
            else
                ans[1] ^= it;
        }
        if(ans[0] > ans[1])
            swap(ans[0], ans[1]);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends