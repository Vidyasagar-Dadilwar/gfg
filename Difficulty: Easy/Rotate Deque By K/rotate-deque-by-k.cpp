class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        if(type == 1){
            while(k--){
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
        else{
            while(k--){
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
        }
    }
};