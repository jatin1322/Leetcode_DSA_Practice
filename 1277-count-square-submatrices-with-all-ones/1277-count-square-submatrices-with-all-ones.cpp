class Solution {
public:
    int solve(vector<vector<int>> &a,
                        int N, int M)
{
    // Initialize count variable
    int count = 0;
 
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            // If a[i][j] is equal to 0
            if (a[i][j] == 0)
                continue;
 
            // Calculate number of
            // square submatrices
            // ending at (i, j)
            a[i][j] = min(min(a[i - 1][j],
                              a[i][j - 1]),
                          a[i - 1][j - 1])
                      + 1;
        }
    }
 
    // Calculate the sum of the array
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            count += a[i][j];
 
    return count;
}
 
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        return solve(matrix,m,n);
    }
};