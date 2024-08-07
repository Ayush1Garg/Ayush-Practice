// TC: O(V + E)
// SC: O(V + E)
class Solution {
public:
    int bfs(vector<int> adj[], int time, int change, int n){
        vector<int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
        dist1[1] = 0; // We can set node 1, dist1[1] = 0; as it's the minimum we have initially.
        // dist2[1] = 0; // It will give the Wrong Answer, as we don't have a second minimum time, so initially, we can't allocate dist2[1] to 0.
        
        // {dist, node}
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        
        while(!q.empty() && dist2[n] == INT_MAX){
            int node = q.front().second, currentDist = q.front().first;
            q.pop();

            // Wait if light is red, if odd.
            // light : green in [0, c),  [2c, 3c), ... 
            // red  in [c, 2c), [3c, 4c), ...
            if((currentDist/change)%2 == 1){
                currentDist += change - currentDist%change;
            }

            for(auto it: adj[node]){
                if(dist1[it] > currentDist + time){
                    dist1[it] = currentDist + time;
                    q.emplace(dist1[it], it);
                }else if(dist2[it] > currentDist + time && currentDist + time != dist1[it]){
                    dist2[it] = currentDist + time;
                    q.emplace(dist2[it], it);
                }
            }
        }
        return dist2[n];
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> graph[n + 1];
        
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
      
        return bfs(graph, time, change, n);
    }
};