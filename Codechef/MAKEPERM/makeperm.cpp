#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int mini = *min_element(arr.begin(), arr.end());
        int cnt = count(arr.begin(), arr.end(), n);
        if(mini==1 && cnt<=1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}