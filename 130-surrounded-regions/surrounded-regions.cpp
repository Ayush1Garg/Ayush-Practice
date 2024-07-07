class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>>& vis, int n, int m){
        if(i<0 || j<0 || i==n || j==m || vis[i][j] || board[i][j]!='O') return;
        vis[i][j] = true;
        dfs(i+1,j,board,vis,n,m);
        dfs(i-1,j,board,vis,n,m);
        dfs(i,j+1,board,vis,n,m);
        dfs(i,j-1,board,vis,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m = board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        for(int i=0; i<m; i++){
            if(board[0][i]=='O'){
                dfs(0,i,board,vis,n,m);
            }
            if(board[n-1][i]=='O'){
                dfs(n-1,i,board,vis,n,m);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,vis,n,m);
            }
            if(board[i][m-1]=='O'){
                dfs(i,m-1,board,vis,n,m);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};