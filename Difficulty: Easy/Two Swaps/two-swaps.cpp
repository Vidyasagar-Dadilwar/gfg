//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
       vector<int>temp=arr;
       sort(temp.begin(),temp.end());
       
       int cnt=0;
       int prev=INT_MAX;
       bool check =true;
       for(int i=0;i<arr.size();i++){
           {if(arr[i]!=temp[i]) cnt++;
               if(arr[i]<prev) prev=arr[i];
               else check=false;
           }
       }
       return cnt==0 || cnt==3 || (cnt==4 && check);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends