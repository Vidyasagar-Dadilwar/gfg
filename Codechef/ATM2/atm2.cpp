#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(auto i: arr){
            if(k-i>=0){
                k=k-i;
                cout<<1;
            }
            else{
                cout<<0;
            }
        }
        cout<<endl;
    }
}
