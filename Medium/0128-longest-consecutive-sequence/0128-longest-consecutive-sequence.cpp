class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());
        int maxLen=0, len=0;
        for(auto it: numSet){
            if(numSet.find(it-1) == numSet.end()){
                int curr = it;
                len=1;
                while(numSet.find(curr+1) != numSet.end()){
                    curr+=1;
                    len+=1;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};