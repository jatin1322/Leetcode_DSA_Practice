class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        int n=matrix.size();
        int m=matrix[0].size();
         if(target<matrix[0][0] || target>matrix[n-1][m-1]) return false;
        int i;
        for(i=1;i<n;i++){
            if(target<matrix[i][0]){
                break;
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[i-1][j]==target) return true;
        }
        return false;
    }
    
};