//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int node, vector<bool>& vis, vector<int> adj[], int prev = -1){
        vis[node] = true;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i]==prev) continue;
            if(vis[adj[node][i]]) return true;
            dfs(adj[node][i],vis,adj,node);
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        for(int i=0; i<v; i++){
            vector<bool> vis(v,false);
            if(dfs(i,vis,adj,v)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends