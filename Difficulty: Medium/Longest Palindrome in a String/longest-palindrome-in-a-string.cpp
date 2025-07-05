//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string palindrome(string s, int i, int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--;j++;
        }
        return s.substr(i+1, j-i-1);
    }
    string longestPalindrome(string &s) {
        // code here
        string ans = "";
        
        for(int i=0; i<s.size(); i++){
            string odd = palindrome(s, i, i);
            ans = (ans.size() >= odd.size()) ? ans : odd;
            
            string even = palindrome(s, i, i+1);
            ans = (ans.size() >= even.size()) ? ans : even;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends