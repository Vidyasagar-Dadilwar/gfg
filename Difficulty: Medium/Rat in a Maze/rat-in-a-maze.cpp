class Solution {
  public:
    vector<pair<int,int>> dirs = {{1,0}, {0,-1}, {-1,0}, {0,1}};
    string moves = "DLUR";
    void solve(vector<vector<int>>& maze, int i, int j, int n, int m, string& curr, vector<string>& ans){
        if(i == n-1 && j == m-1 && maze[i][j] == 1){
            ans.push_back(curr);
            return;
        }
        auto t = maze[i][j];
        maze[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            int x = i + dirs[k].first, y = j + dirs[k].second;
            if (x>=0 && x<n && y>=0 && y<m && maze[x][y]==1) {
                curr.push_back(moves[k]);
                solve(maze, x, y, n, m, curr, ans);
                curr.pop_back();
            }
        }
        maze[i][j] = t;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        string curr = "";
        int n = maze.size(), m = maze[0].size();
        if(maze[0][0] == 0) return {};
        solve(maze, 0, 0, n, m, curr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};