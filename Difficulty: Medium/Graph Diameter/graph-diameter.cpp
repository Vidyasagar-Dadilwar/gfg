class Solution {
  public:
    void bfs(vector<vector<int>>& adj, int V, int src, vector<int>& dist){
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto& n: adj[curr]){
                if(!vis[n]){
                    vis[n] = 1;
                    q.push(n);
                    dist[n] = dist[curr]+1;
                }
            }
        }
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e: edges){
            int n1 = e[0], n2 = e[1];
            adj[n1].push_back(n2);
            adj[n2].push_back(n1);
        }
        vector<int> dist(V, -1);
        dist[0] = 0;
        bfs(adj, V, 0, dist);
        int f = max_element(dist.begin(), dist.end()) - dist.begin();
        dist[f] = 0;
        bfs(adj, V, f, dist);
        return *max_element(dist.begin(), dist.end());
    }
};
