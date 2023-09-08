class Solution {
public:
    void dfs(int node, int n, vector<vector<int>>& connects, vector<bool> &vis){
        vis[node] = true;
        for(int i=0; i<n; i++){
            if(connects[node][i] && !vis[i])
                dfs(i,n,connects,vis);
        }
    }

    int findCircleNum(vector<vector<int>>& connects) {
        int n = connects.size();
        int ans = 0;
        vector<bool> vis(n,false);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i,n,connects,vis);
            }
        }
        return ans;
    }
};