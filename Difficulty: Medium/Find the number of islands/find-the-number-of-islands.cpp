//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
  void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[row][col] = 1; // Mark the starting cell as visited
    queue<pair<int, int>> q;
    q.push({row, col}); // Push the starting cell into the queue
    
    int n = grid.size(); 
    int m = grid[0].size(); 
    
    // BFS loop: explore all connected '1's (i.e., the current island)
    while (!q.empty()) {
        int currentRow = q.front().first; 
        int currentCol = q.front().second; 
        q.pop();
        
        // Traverse the 8 possible directions (up, down, left, right, and 4 diagonals)
        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                int newRow = currentRow + delRow;
                int newCol = currentCol + delCol;
                
                // Check if the new position is within bounds, is land, and not visited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                    && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1; // Mark the new land cell as visited
                    q.push({newRow, newCol}); // Add it to the queue for further exploration
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Visited array to keep track of explored cells
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0; // Island counter
    
    // Traverse the grid cell by cell
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If the current cell is land and has not been visited, it is a new island
            if (!vis[row][col] && grid[row][col] == '1') {
                count++; // Increment the island count
                bfs(row, col, vis, grid); // Perform BFS to mark the entire island as visited
            }
        }
    }
    
    return count; // Return the total number of islands found
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends