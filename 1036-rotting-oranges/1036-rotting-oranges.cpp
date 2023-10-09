class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int f = 0, r = 0;
        queue<pair<int,int>> pq;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2)
                {
                    pq.push({i,j});
                }
                else if(grid[i][j]==1){
                    f++;
                }
            }
        }
        if(f==0) return 0;
        int mins = 0;
        vector<pair<int,int>> dir = {{-1,0}, {0,-1}, {0,1}, {1,0}};
        while(!pq.empty() && f>0){
            mins++;
            int size = pq.size();
            while(size>0){
                int i = pq.front().first;
                int j = pq.front().second;
                pq.pop();
                size--;
                for(auto d: dir){
                    int r = i + d.first;
                    int c = j + d.second;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]==1){
                        grid[r][c] = 2;
                        pq.push({r,c});
                        f--;
                    }
                }
            }
        }
        if(f>0) return -1;
        return mins;
    }
};