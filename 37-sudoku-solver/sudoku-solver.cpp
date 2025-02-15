class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col,char num) {
        for(int idx = 0; idx < 9; ++idx)
            if(board[row][idx] == num || board[idx][col] == num)
                return false;
        int st_row = row / 3 * 3, st_col = col / 3 * 3;
        for (int i = st_row; i < st_row + 3; i++) 
            for (int j = st_col; j < st_col + 3; j++) 
                if (board[i][j] == num) 
                    return false;
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            for(int col= 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num; 
                            if (solveSudoku(board)) return true;
                            board[row][col] = '.'; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};