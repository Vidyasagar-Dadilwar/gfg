#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            if(i==0 || i==n-1){
                cout<<"0";
            }
            else{
                cout<<"1";
            }
        }
        cout<<endl;
    }
}
