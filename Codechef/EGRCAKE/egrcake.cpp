#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int tmp = gcd(n,m);
        if(tmp == 1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No "<<n/tmp<<endl;
        }
    }
}
