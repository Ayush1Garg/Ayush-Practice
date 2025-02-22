class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int size = m * n;
        vector<int> ans;
        
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        
        while (ans.size() < size) {
            // Move right
            for (int j = left; j <= right && ans.size() < size; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;
            
            // Move down
            for (int i = top; i <= bottom && ans.size() < size; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            
            // Move left
            for (int j = right; j >= left && ans.size() < size; j--) {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
            
            // Move up
            for (int i = bottom; i >= top && ans.size() < size; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        
        return ans;
    }
};
