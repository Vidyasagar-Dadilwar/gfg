class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        priority_queue<double> pq;
        double csum = accumulate(arr.begin(), arr.end(), 0);
        double osum = csum / 2;
        for(int i: arr)
            pq.push(1.0*i);
        int cnt = 0;
        while(!pq.empty() && csum > osum){
            double d = pq.top();
            pq.pop();
            csum -= (d/2);
            pq.push(d/2);
            cnt++;
        }
        return cnt;
    }
};