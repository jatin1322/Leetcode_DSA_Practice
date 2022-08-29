class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char> >&matrix){
    if(i<0 || j<0 || i>=n ||j>=m || matrix[i][j]!='1') return ;
    matrix[i][j]='#';
    dfs(i-1,j,n,m,matrix);
    dfs(i+1,j,n,m,matrix);
    dfs(i,j-1,n,m,matrix);
    dfs(i,j+1,n,m,matrix);
    
}

    int numIslands(vector<vector<char>>& A) {
        
         int n=A.size();
   int m=A[0].size();
   int cnt=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(A[i][j]=='1'){cnt++; dfs(i,j,n,m,A);}
           
       }
   }
       return cnt; 
    }
};