// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        int maxi = *max_element(arr.begin(), arr.end()), large = -1;
        for(auto i: arr){
            if(i>large && i<maxi)
                large=i;
        }
        return large;
    }
};
