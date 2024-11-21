class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mp(m, vector<int>(n,0));
        for(auto w: walls){
            mp[w[0]][w[1]]=-1;
        }
        for(auto g: guards){
            mp[g[0]][g[1]]=1;
        }
        vector<pair<int, int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        for(auto &g: guards){
            for(auto &d: dir){
                int x=g[0], y=g[1];
                while(1){
                    x+=d.first;
                    y+=d.second;

                    if(x<0 || y<0 || x>=m || y>=n || mp[x][y]==1 || mp[x][y]==-1){
                        break;
                    }
                    mp[x][y]=2;
                }
            }
        }
        int cnt = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mp[i][j]==0)
                    cnt++;
            }
        }
        return cnt;
    }
};