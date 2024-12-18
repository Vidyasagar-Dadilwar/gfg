#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        cin>>n>>k>>x;
        if(k*(k+1)/2 <= x){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}
