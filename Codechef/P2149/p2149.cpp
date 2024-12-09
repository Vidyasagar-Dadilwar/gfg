#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	   int a,b,x;
	   cin>>a>>b>>x;
	   int k = x*x;
	   if(a*b <= k) cout<<0<<endl;
	   else if(a>k && b>k) cout<<2<<endl;
	   else cout<<1<<endl;
	}
}