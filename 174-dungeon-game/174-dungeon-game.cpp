
class Solution {
public:
    
int getVal(vector<vector<int>> &mat, vector<vector<int>> &dp , int i=0, int j=0)
    {
        int n = mat.size();
        int m = mat[0].size();    
        
        if(i == n || j == m)    return 1e9; 
        
        if(i == n-1 and j == m-1)
            return (mat[i][j] <= 0) ? -mat[i][j] + 1 : 1;
        
         
        if( dp[i][j] != 1e9)
            return dp[i][j];
        
        int IfWeGoRight = getVal(mat , dp , i , j+1);
        int IfWeGoDown = getVal(mat , dp , i+1 , j);
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) -mat[i][j];
        
        
        dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;      
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int n = dungeon.size();
        int m = dungeon[0].size();
        
        vector<vector<int>> dp(n , vector<int>(m , 1e9));
        
        return getVal(dungeon, dp);     
    }
};

// class Solution {
// public:

//     int solve(vector<vector<int>> &arr,int i, int j,vector<vector<int>> dp) { 
//         int n=arr.size();
//         int m=arr[0].size();
//       if (i ==n || j ==m) 
//          return 1e9; 
//       else if(i==n-1 && j==m-1) 
//          return  (arr[i][j] <= 0) ? -arr[i][j] + 1 : 1;
//         if(dp[i][j]!=-1) return dp[i][j];
//  int right=solve(arr,i,j+1,dp);
//         int down=solve(arr,i+1,j,dp);
//      int health=min(right,down)-arr[i][j];
//         if(health<=0){
//             return dp[i][j]=1;
//         }
//         else return dp[i][j]=health;
//     } 
//     int calculateMinimumHP(vector<vector<int>>& dungeon) {
//     int n=dungeon.size();
//         int m=dungeon[0].size();
//        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return solve(dungeon,0,0,dp);
        
// //         int ans;
// //         if(dungeon[0][0]<0) ans=abs(dungeon[0][0])+1;
// //         else ans=0;
// //         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<m;j++){
// //                 int a=1e9,b=1e9;
// //                 if(i>0){ a=dp[i-1][j]; }
// //                 if(j>0){ b=dp[i][j-1]; }
                
                   
// //             }
// //         }
        
        
//     }
// };