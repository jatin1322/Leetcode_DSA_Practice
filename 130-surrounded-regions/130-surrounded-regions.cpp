class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char> >&matrix){
    if(i<0 || j<0 || i>=n ||j>=m || matrix[i][j]!='O') return ;
    matrix[i][j]='#';
    dfs(i-1,j,n,m,matrix);
    dfs(i+1,j,n,m,matrix);
    dfs(i,j-1,n,m,matrix);
    dfs(i,j+1,n,m,matrix);
    
}
    void solve(vector<vector<char>>& A) {
        
         int n=A.size();
   int m=A[0].size();
   
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(i==0 && A[i][j]=='O') dfs(i,j,n,m,A);
           if(i==n-1 && A[i][j]=='O' ) dfs(i,j,n,m,A);
           if(j==0 && A[i][j]=='O' ) dfs(i,j,n,m,A);
           if(j==m-1 && A[i][j]=='O' ) dfs(i,j,n,m,A);
       }
   }
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(A[i][j]=='O') A[i][j]='X';
       }
   }
    for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(A[i][j]=='#') A[i][j]='O';
       }
   }
   
        
    }
};