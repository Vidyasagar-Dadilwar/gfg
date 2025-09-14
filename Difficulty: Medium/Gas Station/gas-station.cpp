class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int totalG = 0, totalC = 0, currG = 0, start = 0;
        for(int i=0; i<gas.size(); i++){
            totalG += gas[i];
            totalC += cost[i];
        }
        
        if(totalG < totalC)
            return -1;
            
        for(int i=0; i<gas.size(); i++){
            currG += gas[i] - cost[i];
            if(currG < 0){
                currG = 0;
                start = i+1;
            }
        }
        return start;
    }
};