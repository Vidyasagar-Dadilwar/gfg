class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int l = -1, h = -1;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == x){
                if(l == -1)
                    l = i;
                h = i;
            }
        }
        if(l == -1 && h == -1)
            return {-1, -1};
        else
            return {l, h};
    }
};