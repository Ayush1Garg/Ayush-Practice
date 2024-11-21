class Solution {
public:
    void matrixFill(vector<vector<char>> &matrix, int row, int col, int m, int n) {
    
    // Down direction
    for (int i = row + 1; i < m; i++) {
        if (matrix[i][col] == 'W' || matrix[i][col] == 'G') 
            break;  // Stop at wall or guard

        matrix[i][col] = 'S'; //Mark safe by 'S'
    }

    // Right direction
    for (int j = col + 1; j < n; j++) {
        if (matrix[row][j] == 'W' || matrix[row][j] == 'G') 
            break; 

        matrix[row][j] = 'S';
    }

    // Up direction
    for (int i = row - 1; i >= 0; i--) {
        if (matrix[i][col] == 'W' || matrix[i][col] == 'G') 
            break;

        matrix[i][col] = 'S';
    }

    // Left direction
    for (int j = col - 1; j >= 0; j--) {
        if (matrix[row][j] == 'W' || matrix[row][j] == 'G')
            break; 

        matrix[row][j] = 'S';
    }
}

int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
    vector<vector<char>> matrix(m, vector<char>(n, '.'));

    // Mark guards
    for (auto &guard : guards) {
        int row = guard[0];
        int col = guard[1];
        matrix[row][col] = 'G';
    }

    // Mark walls
    for (auto &wall : walls) {
        int row = wall[0];
        int col = wall[1];
        matrix[row][col] = 'W';
    }

    // Fill guarded areas
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 'G') {
                matrixFill(matrix, i, j, m, n);
            }
        }
    }

    // Count unguarded cells
    int countUnguardedCells = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '.') {
                countUnguardedCells++;
            }
        }
    }

    return countUnguardedCells;
}
};