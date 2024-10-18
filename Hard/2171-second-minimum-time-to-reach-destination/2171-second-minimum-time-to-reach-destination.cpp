class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n + 1);
        for(auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        queue<pair<int, int>>q;
        // <node, freq(pushed into the q)>
        q.push({1, 1});
        dist1[1]= 0;
        while(q.size())
        {
            auto [u, freq] = q.front();
            q.pop();
            int w = freq == 1? dist1[u] : dist2[u];
            for(int v : adj[u])
            {
                if(dist1[v] == INT_MAX)
                {
                    dist1[v] = w + 1;
                    q.push({v, 1});
                }
                else if(dist2[v] == INT_MAX && (dist1[v] != w + 1))
                {
                    dist2[v] = w + 1;
                    q.push({v, 2});
                }
            }
        }
        int secondmin = dist2[n];
        int ans = 0;
        for(int i = 0; i < secondmin; i ++)
        {
            int t = ans / change;
            if(t%2) ans += change * (t + 1) - ans;
            ans += time;
        }
        return ans;
    }
};
auto init = []()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return nullptr;
}();