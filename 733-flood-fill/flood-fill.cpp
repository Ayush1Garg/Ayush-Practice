class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& newImage, int& newColor, int& oldColor){
        if(i<0 || j<0 || i>=newImage.size() || j>=newImage[0].size()) return;
        if(newImage[i][j]==newColor || newImage[i][j]!=oldColor) return;
        newImage[i][j] = newColor;
        dfs(i+1,j,newImage,newColor,oldColor);
        dfs(i-1,j,newImage,newColor,oldColor);
        dfs(i,j+1,newImage,newColor,oldColor);
        dfs(i,j-1,newImage,newColor,oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<vector<int>> ans = image;
        int prevcol = image[sr][sc];
        dfs(sr,sc,ans,color,prevcol);
        return ans;
    }
};