class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& i1, vector<vector<int>>& i2) {
        vector<vector<int>>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<i1.size();i++){
            for(int j=0;j<i2.size();j++){
                if(i1[i][0]==i2[j][0]){
                    mp[i1[i][0]]=i1[i][1]+i2[j][1];
                }
            }
        }
        for(int i=0;i<i1.size();i++){
            if(!mp[i1[i][0]])mp[i1[i][0]]=i1[i][1];
        }
        for(int i=0;i<i2.size();i++){
            if(!mp[i2[i][0]])mp[i2[i][0]]=i2[i][1];
        }
        for(auto x:mp){
            vector<int>v;
            v.push_back(x.first);
            v.push_back(x.second);
            ans.push_back(v);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};