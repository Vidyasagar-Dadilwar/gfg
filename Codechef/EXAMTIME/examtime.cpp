#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int d1, d2, d3;
        cin>>d1>>d2>>d3;
        int s1, s2, s3;
        cin>>s1>>s2>>s3;
        
        if(d1+d2+d3 > s1+s2+s3){
            cout<<"Dragon\n";
        }
        else if(d1+d2+d3 < s1+s2+s3){
            cout<<"Sloth\n";
        }
        else{
            if(d1>s1){
                cout<<"Dragon\n";
            }
            else if(d1<s1){
                cout<<"Sloth\n";
            }
            else if(d2>s2){
                cout<<"Dragon\n";
            }
            else if(d2<s2){
                cout<<"Sloth\n";
            }
            else{
                cout<<"Tie\n";
            }
        }
    }
}
