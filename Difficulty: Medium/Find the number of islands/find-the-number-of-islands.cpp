//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int& n, int& m){
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || grid[i][j]=='0') return;
        vis[i][j] = true;
        dfs(i+1,j,grid,vis,n,m);
        dfs(i-1,j,grid,vis,n,m);
        dfs(i,j+1,grid,vis,n,m);
        dfs(i,j-1,grid,vis,n,m);
        dfs(i+1,j-1,grid,vis,n,m);
        dfs(i-1,j-1,grid,vis,n,m);
        dfs(i+1,j+1,grid,vis,n,m);
        dfs(i-1,j+1,grid,vis,n,m);
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
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
    }
    return 0;
}
// } Driver Code Ends