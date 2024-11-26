class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[i]=0;
        }
        for(auto edge: edges){
            mp[edge[1]]++;
        }
        vector<pair<int, int>> sortedMp(mp.begin(), mp.end());
        sort(sortedMp.begin(), sortedMp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        if(sortedMp.size()>1 && sortedMp[0].second == sortedMp[1].second){
            return -1;
        }
        else{
            return sortedMp[0].first;
        }
    }
};