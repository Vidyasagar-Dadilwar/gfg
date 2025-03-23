class Solution {
public:
    const int MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto& road: roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        pq.push({0, 0});
        dist[0] = 0; ways[0] = 1;

        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            if(time > dist[node])
                continue;
            for(auto& [neighbor, travelTime] : adj[node]) {
                long long newTime = time + travelTime;
                if(newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    ways[neighbor] = ways[node];
                    pq.push({newTime, neighbor});
                } 
                else if(newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};