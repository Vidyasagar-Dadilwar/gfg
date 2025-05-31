class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        priority_queue<int> pq;
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                pq.push(mat[i][j]);
                
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        while(!pq.empty() && pq.size() == 1){
            pq.pop();
        }
        return pq.top();
    }
};