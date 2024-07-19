
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> result;
        
        for (int i = 0; i < matrix.size(); i++) {
            int minCol = findMinColumn(matrix, i);
            int candidate = matrix[i][minCol];
            
            if (isMaxInColumn(matrix, candidate, minCol)) {
                result.push_back(candidate);
            }
        }
        
        return result;
    }
    
private:
    int findMinColumn(const vector<vector<int>>& matrix, int row) {
        return min_element(matrix[row].begin(), matrix[row].end()) - matrix[row].begin();
    }
    
    bool isMaxInColumn(const vector<vector<int>>& matrix, int val, int col) {
        return all_of(matrix.begin(), matrix.end(), [val, col](const auto& row) {
            return row[col] <= val;
        });
    }
};