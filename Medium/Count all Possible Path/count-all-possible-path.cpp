//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    int timer = 1;
public:
    bool dfs(int par, int node, int n, vector<int> &vis, vector<int> &deg, vector<vector<int>> &paths, int &odd_deg, vector<int> &tin, vector<int> &low){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for(int i=0; i<n; i++){
            if(paths[node][i]==1){
                deg[node]++;
                if(i==par) continue;
                if(vis[i]==0){
                    bool check = dfs(node,i,n,vis,deg,paths,odd_deg,tin,low);
                    if(check) return true;
                    low[node] = min(low[i],low[node]);
                    if(low[i]>tin[node]) return true;
                }
                else{
                    low[node] = min(low[i],low[node]);
                }
            }
        }
        if(deg[node]%2==1) odd_deg++;
        return false;
    }
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n = paths.size();
	    if(n==1) return 1;
	    if(n==2) return 0;
	    vector<int> vis(n,0), degree(n,0), tin(n,0), low(n,0);
	    int odd_deg = 0;
	    bool bridges = dfs(-1,0,n,vis,degree,paths,odd_deg, tin,low);
	    if(odd_deg!=0) return 0;
	    for(int i=0; i<n; i++){
	        if(vis[i]!=1) return 0;
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends