//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void print(vector<vector<int>> &v, int n){
        for(auto row:v){
            for(auto ele : row) cout<<ele<<" ";
            cout<<endl;
        }
        
    }
    void floydWarshall(vector<vector<int>> &dist, int V)
    {
        int i, j, k;
    
        /* Add all vertices one by one to the set of intermediate vertices. 
        ---> Before start of a iteration, we have shortest distances between all pairs of vertices 
        such that the shortest distances consider only the vertices in set {0, 1, 2, .. k-1} 
        as intermediate vertices. ----> After the end of a iteration, vertex no. 
        k is added to the set of intermediate vertices and the set becomes {0, 1, 2, .. k} */
        for (k = 0; k < V; k++) {
            // Pick all vertices as source one by one
            for (i = 0; i < V; i++) {
                // Pick all vertices as destination for the
                // above picked source
                for (j = 0; j < V; j++) {
                    // If vertex k is on the shortest path from
                    // i to j, then update the value of
                    // dist[i][j]
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                    if(i==j) dist[i][j] = 0;
                }
            }
        }
    }   
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        if(n==1) return 0;
        vector<vector<int>> dist(n,vector<int>(n,10001));
        for(auto edge: edges){
            int i = edge[0], j = edge[1], w = edge[2];
            dist[i][j] = w;
            dist[j][i] = w;
        }
        floydWarshall(dist,n);
        int cities = 0, mincities = INT_MAX, ans = -1;
        // print(dist,n);
        // cout<<endl;
        for(int i=0; i<n; i++){
            cities = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j]<=distanceThreshold) cities++;
            }
            if(cities<=mincities){
                ans = i;
                mincities = cities;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends