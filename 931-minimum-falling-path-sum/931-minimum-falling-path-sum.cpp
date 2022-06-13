class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int c=matrix[0].size();
        for(int i=n-2; i >=0;i--){
            for(int j=0; j<c;j++){
                int a=matrix[i+1][j];
            if(j!=c-1)    a=min(a,matrix[i+1][j+1]);
             if(j!=0)    a=min(a,matrix[i+1][j-1]);   
                matrix[i][j]+=a;
            }
        }
        sort(matrix[0].begin(),matrix[0].end());
        return matrix[0][0];
    }
};