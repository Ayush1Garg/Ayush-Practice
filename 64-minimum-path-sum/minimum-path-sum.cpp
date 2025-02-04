class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int first = grid[0][0];
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                grid[i][j] += min( (i>0 ? grid[i-1][j] : 40000) , (j>0 ? grid[i][j-1] : 40000) );
                if(i==0 && j==0) grid[i][j] = first;
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};