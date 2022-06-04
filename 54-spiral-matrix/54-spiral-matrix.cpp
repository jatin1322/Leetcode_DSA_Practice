class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int total_steps = m * n;
        vector<int> res;
        
        // int k = 0;
        int first_row = 0;
        int last_col = n - 1;
        int last_row = m - 1;
        int first_col = 0;
        
        while (first_row <= last_row && first_col <= last_col) {
            
            // traverse upper row.
            for (int j = first_col; j <= last_col; j++) {
                res.push_back(matrix[first_row][j]);
            }
            
            // traverse right column.
            for (int i = first_row + 1; i <= last_row; i++) {
                res.push_back(matrix[i][last_col]);
            }
            
            // traverse bottom row, make sure we won't traverse the same row twice.
            if (last_row != first_row) {
                for (int j = last_col - 1; j >= first_col; j--) {
                    res.push_back(matrix[last_row][j]);
                }
            }
            
            // traverse left column, make sure we won't traverse the same column twice.
            if (first_col != last_col) {
                for (int i = last_row - 1; i > first_row; i--) {
                    res.push_back(matrix[i][first_col]);
                }
            }
            
            // update boundary for next spiral matrix
            first_row++;
            last_col--;
            last_row--;
            first_col++;
        }
        
        return res;
    }
};