// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int maxi = 0, ind = -1;
        for(int i=0; i<arr.size(); i++){
            int cnt = count(arr[i].begin(), arr[i].end(), 1);
            if(maxi < cnt){
                maxi = cnt;
                ind = i;
            }
        }
        return ind;
    }
};