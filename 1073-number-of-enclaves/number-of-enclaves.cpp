class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    void dfs(int i, int j, vector<vector<int>>& board, int n, int m){
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=1) return;
        board[i][j] = 0;
        dfs(i+1,j,board,n,m);
        dfs(i-1,j,board,n,m);
        dfs(i,j+1,board,n,m);
        dfs(i,j-1,board,n,m);
    }
    int numEnclaves(vector<vector<int>>& board) {
        int n=board.size(), m = board[0].size();
        for(int i=0; i<m; i++){
            if(board[0][i]==1){
                dfs(0,i,board,n,m);
            }
            if(board[n-1][i]==1){
                dfs(n-1,i,board,n,m);
            }
        }
        for(int i=0; i<n; i++){
            if(board[i][0]==1){
                dfs(i,0,board,n,m);
            }
            if(board[i][m-1]==1){
                dfs(i,m-1,board,n,m);
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                sum += board[i][j];
            }
        }
        return sum;
    }
};