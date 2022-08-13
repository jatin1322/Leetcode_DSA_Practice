class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<vector<int>>> &dp,vector<vector<int>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j2<0 || j1>=m || j2 >=m) return 1e-9;
        if(i==n-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else return grid[i][j1] + grid[i][j2];
            
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=1e-9;
        for (int di = -1; di <= 1; di++) {
    for (int dj = -1; dj <= 1; dj++) {
      int ans;
      if (j1 == j2)
        ans = grid[i][j1] + solve(i + 1, j1 + di, j2 + dj, dp, grid);
      else
        ans = grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + di, j2 + dj, dp,grid);
       
      maxi = max(maxi, ans);
    }
  }
  return dp[i][j1][j2] = maxi;

    
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return solve(0,0,m-1,dp,grid);
    }
};