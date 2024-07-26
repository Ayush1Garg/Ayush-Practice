class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        vector<int>dist(n,0);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                 if(matrix[i][j]<=distanceThreshold){
                    c++;
                 }
            }
            dist[i]=c;
        }
        int min=dist[0],node=0;
        for(int i=1;i<n;i++){
          if(dist[i]<=min){
            min=dist[i];
            node=i;
          }
        }
        return node;
    }
};