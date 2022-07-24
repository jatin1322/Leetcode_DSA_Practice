class Solution {
public:
    int minCost(vector<vector<int>> &cost,int m, int n,vector<vector<int>>& memo) { 
      if (n <0 || m <0) 
         return INT_MAX; 
      else if(m==0 && n==0) 
         return cost[m][n]; 
      if(memo[m][n]!=-1)
          return memo[m][n];
      int r=cost[m][n]+min(minCost(cost,m-1,n,memo),minCost(cost,m,n-1,memo));
        memo[m][n]=r;
      return r;
    } 
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n, -1));
        dp[0][0]=grid[0][0];
       for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0) dp[i][j] = grid[i][j];
            else{
                
                int up = grid[i][j];
                if(i>0) up += dp[i-1][j];
                else up += 1e9;
                
                int left = grid[i][j];
                if(j>0) left+=dp[i][j-1];
                else left += 1e9;
                
                dp[i][j] = min(up,left);
            }
        }
    }

        return dp[m-1][n-1];
    }
    
};
