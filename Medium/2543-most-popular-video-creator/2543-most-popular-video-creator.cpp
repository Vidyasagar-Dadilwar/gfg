#define ll long long
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, set<string>> creatorId;
        map<string, ll> creatorViews;
        map<string, map<ll, set<string>>> creatorViewsId;
        vector<vector<string>> ans;
        ll n = creators.size(), maxiViews = 0;
        for(auto i =0 ; i < n; i++){
            creatorId[creators[i]].insert(ids[i]);
            creatorViews[creators[i]] += 1ll*views[i];
            maxiViews = max(maxiViews, creatorViews[creators[i]]);
            creatorViewsId[creators[i]][views[i]].insert(ids[i]);
        }
        for(auto [creator, views] : creatorViews){
            if(views == maxiViews){
                auto nextMap = creatorViewsId[creator];
                auto maxiId = *((nextMap.rbegin())->second).begin() ;
                ans.push_back({creator, maxiId});
            }
        }
        return ans;
    }
};