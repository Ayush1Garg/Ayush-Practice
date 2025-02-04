class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1]==1) return 0;
        vector<int> prevRow(m,1), prevCol(n,1);
        bool obstacle = false;
        for(int i=0; i<m; i++){
            if(obstacleGrid[0][i]==1) obstacle = true;
            if(obstacle) prevRow[i] = 0;
        }
        if(n==1) return prevRow[m-1];
        obstacle = false;
        for(int i=0; i<n; i++){
            if(obstacleGrid[i][0]==1) obstacle = true;
            if(obstacle) prevCol[i] = 0;
        }
        if(m==1) return prevCol[n-1];
        vector<int> currRow(m,0);
        int up = 0, left = 0, present = 0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                up = prevRow[j];
                left = prevCol[i];
                present = (1 - obstacleGrid[i][j])*(up + left);
                prevRow[j] = present;
                prevCol[i] = present;
            }
        }
        // cout<<prevCol[n-1]<<" "<<prevRow[m-1]<<endl;
        return prevCol[n-1];
    }
};