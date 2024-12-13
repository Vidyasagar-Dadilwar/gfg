#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        if(n==2){
            cout<<"NO\n";
        }
        else if(arr[n-1] != arr[n-2]){
            if(arr[0] == arr[n-1]){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
        else{
            if(arr[n/2-1] == arr[n-1]){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
    }
}
