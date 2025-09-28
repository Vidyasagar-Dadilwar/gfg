
class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        deque<int> mini, maxi;
        int n = arr.size(), s = 0, e = 0;
        int ss = 0, ee = 0;
        while(e < n){
            while(!mini.empty() && arr[mini.back()] > arr[e])
                mini.pop_back();
            
            while(!maxi.empty() && arr[maxi.back()] < arr[e])
                maxi.pop_back();
                
            mini.push_back(e);
            maxi.push_back(e);
            
            while(arr[maxi.front()] - arr[mini.front()] > x){
                if(s == mini.front())
                    mini.pop_front();
                if(s == maxi.front())
                    maxi.pop_front();
                s++;
            }
            if(e - s + 1 > ee - ss + 1){
                ss = s;
                ee = e;
            }
            e++;
        }
        vector<int> res;
        for(int i=ss; i<=ee; i++)
            res.push_back(arr[i]);
        
        return res;
    }
};

