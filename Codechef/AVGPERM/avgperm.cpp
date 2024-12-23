#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        arr.push_back(n-1);
        arr.push_back(n-2);
        for(int i=1; i<n-3; i++){
            arr.push_back(i);
        }
        if(n>3){
            arr.push_back(n-3);
        }
        arr.push_back(n);
        for(auto i: arr){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
