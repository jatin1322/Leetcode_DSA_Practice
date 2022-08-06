class Solution {
public:
    
      int dfs(int i,int j,int n,int m,vector<vector<int> >&matrix){
    if(i<0 || j<0 || i>=n ||j>=m || matrix[i][j]!=1) return 0;
          
    matrix[i][j]=2;
   return 1+dfs(i-1,j,n,m,matrix)
   + dfs(i+1,j,n,m,matrix)
   + dfs(i,j-1,n,m,matrix)
   + dfs(i,j+1,n,m,matrix);
    
}

    
    int maxAreaOfIsland(vector<vector<int>>& A) {
          int n=A.size();
   int m=A[0].size();
   int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(A[i][j]==1){ 
               cnt=max(cnt,dfs(i,j,n,m,A));}
           
       }
   }
       return cnt; 
    }
    
};