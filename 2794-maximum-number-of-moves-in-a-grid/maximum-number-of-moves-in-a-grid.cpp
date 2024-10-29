class Solution {
public:
    int help(int i, int j, int n, int m, vector<vector<int>>& grid,int prev, vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]<=prev) return -1;
        if(dp[i][j]!=-2) return dp[i][j];
        int case1 = 1 + help(i-1,j+1,n,m,grid,grid[i][j],dp);
        int case2 = 1 + help(i,j+1,n,m,grid,grid[i][j],dp);
        int case3 = 1 + help(i+1,j+1,n,m,grid,grid[i][j],dp);
        return dp[i][j] = max(case1,max(case2,case3));
    }
    int maxMoves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = grid.size(), m = grid[0].size(), val = 0, ans = 0;
        vector<vector<int>> dp(n,vector<int>(m,-2));
        for(int i=0; i<n; i++){
            val = help(i,0,n,m,grid,0,dp);
            ans = max(val,ans);
        }
        return ans;
    }
};