#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int d, x, y;
        cin>>d>>x>>y;
        int cnt = 0;
        if(x<=y){
            cout<<cnt<<endl;
        }
        else{
            while(--y){
                cnt++;
                float dis = x - x*d*cnt/100 ;
                if(dis <= y){
                    break;
                }
            }
            if(y!=0){
                cout<<cnt<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
    }
}
