class Solution {
public:
        int solve(int i,int j,vector<vector<int>> &dp,vector<vector<int>>& grid){
         if(i<0 || j<0 || grid[i][j]==1)return 0;
            if(i==0 && j==0 ) return 1;
            
       
        if(dp[i][j]!=-1)return dp[i][j];
        int up=solve(i-1,j,dp,grid);
       int left =solve(i,j-1,dp,grid);
        return dp[i][j]=up+left;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int> (n,0));
            for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
              if(grid[i][j]==1){dp[i][j]=0; continue;}
              if(i==0 && j==0) {dp[i][j]=1; continue;}
              if(i>0) dp[i][j]+=dp[i-1][j];
              if(j>0) dp[i][j]+=dp[i][j-1];
           } 
        }
        return dp[m-1][n-1];
    }
};