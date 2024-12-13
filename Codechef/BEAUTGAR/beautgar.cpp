#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s.push_back(s[0]);
        int r=0, g=0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == s[i+1]){
                if(s[i] == 'R')
                    r++;
                else
                    g++;
            }
        }
        if((r==1 && g==1) || (r==0 && g==0)){
            cout<<"yes\n";
        }
        else{
            cout<<"no\n";
        }
    }
}
