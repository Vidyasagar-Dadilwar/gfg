class Solution {
public:
    int minGroups(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<arr.size(); i++){
            int f = arr[i][0], s = arr[i][1];
            if(pq.empty() || pq.top()>=f){
                pq.push(s);
            }
            else{
                pq.pop();
                pq.push(s);
            }
        }
        return pq.size();
    }
};