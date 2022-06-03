typedef vector<int> VI;
typedef vector<VI> VVI;
class NumMatrix {
private:
        int prefixSum[200+3][200+3];
public:
    NumMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        memset(prefixSum, 0, sizeof(prefixSum));
        
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + mat[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        r1++, c1++, c2++, r2++;
        return prefixSum[r2][c2] - prefixSum[r1-1][c2] - prefixSum[r2][c1-1] + prefixSum[r1-1][c1-1];
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */