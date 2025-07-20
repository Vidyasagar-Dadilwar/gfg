class Solution {
  public:
    int countValid(int n, vector<int>& arr) {
        // code here
        bool flag = false;
        for(auto it: arr){
            if(it == 0)
                flag = true;
        }   
        long long total = 9*pow(10, n-1);
        long long ans = (flag) ? pow(10-arr.size(), n) : (9-arr.size()) * pow(10-arr.size(), n-1);
        return total - ans;
    }
};
