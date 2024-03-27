//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void unsafe(vector<vector<int>> &mat, int i, int j){
        int n = mat.size(), m = mat[0].size();
        if(i>0 && mat[i-1][j]==1){ 
            mat[i-1][j] = -1;
        }
        if(i<n-1 && mat[i+1][j]==1){ 
            mat[i+1][j] = -1;
        }
        if(j>0 && mat[i][j-1]==1){ 
            mat[i][j-1] = -1;
        }
        if(j<m-1 && mat[i][j+1]==1){ 
            mat[i][j+1] = -1;
        }
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0) unsafe(mat,i,j);
            }
        }
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        int ans = INT_MAX;
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == 1)
            {
                q.push({0, {i, 0}});
                vis[i][0] = 1;
            }
        }
        while (!q.empty())
        {
            int dist = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            if (c == m - 1)
                ans = min(ans, dist + 1);

            for (int k = 0; k < 4; k++)
            {
                int nx = r + dx[k];
                int ny = c + dy[k];

                if (nx >= 0 and ny >= 0 and nx < n and ny < m and mat[nx][ny] == 1 and !vis[nx][ny])
                {
                    vis[nx][ny] = 1;
                    q.push({dist + 1, {nx, ny}});
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends