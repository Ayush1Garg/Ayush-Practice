class Solution {
    void transpose(vector<vector<int>> &matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    void mirror(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        mirror(matrix);
    }
};