null...// } Driver Code Ends

class Solution {
public:
int pairsum(vector<int> &arr) {
// code here
int n1 = *max_element(arr.begin(), arr.end());
int n2;
for(auto i: arr){
if(i>n2 && i<n1){
n2 = i;
}
