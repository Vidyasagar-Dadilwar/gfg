class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int i=a.size()-1, j=0;
        int n = a.size(), m = b.size();
        
        while(i>=0 && j<m){
            if(a[i] > b[j])
                swap(a[i--], b[j++]);
            else
                break;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};