// User function Template for C++
class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end()); 
        int low = 0, high = n - 1, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int h = n - mid;
            if (citations[mid] >= h) {
                ans = h;         
                high = mid - 1;  
            } 
            else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};