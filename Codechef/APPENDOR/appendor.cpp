#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n, y;
        cin>>n>>y;
        int orr = 0, tmp;
        for(int i=0; i<n; i++){
            cin>>tmp;
            orr |= tmp;
        }
        int req = orr ^ y;
        if((req|orr) == y){
            cout<<req<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}
