//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    // Function to calculate the maximum area of a rectangle
    // in the given matrix.
    int solve(vector<int>& arr) {
        int n = arr.size(), res = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                int tp = st.top();
                st.pop();
                
                int width = st.empty() ? i : i - st.top() - 1;
                res = max(res, arr[tp] * width);
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int tp = st.top();
            st.pop();
            
            int width = st.empty() ? n : n - st.top() - 1;
            res = max(res, arr[tp] * width);
        }
        return res;
    }
    
    int maxArea(vector<vector<int>>& mat) {
        if (mat.empty()) 
            return 0;
        
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        
        vector<int> arr(m, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr[j] = (mat[i][j] == 1) ? arr[j] + 1 : 0;
            }
            ans = max(ans, solve(arr));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(mat) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends