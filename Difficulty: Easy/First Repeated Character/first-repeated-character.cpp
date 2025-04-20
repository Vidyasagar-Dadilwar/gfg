//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string firstRepChar(string s) {
        // code here.
        unordered_map<char, int> mp;
        string f = "";
        for(auto i: s){
            mp[i]++;
            if(mp[i] > 1){
                f += i;
                return f;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.
//    Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.firstRepChar(str) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends