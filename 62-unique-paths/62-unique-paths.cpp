class Solution {
public:
    long long int nCr(int n, int r){
        // code here]
        long long int dp[n+1][n+1];
        if(n<r){
           return 0;
        }
        for(long long int i=0; i<=n; i++){
            for(long long int j=0; j<i+1; j++){
                if(j == 0 || i == j){
                    dp[i][j] = 1;
                }
                else{
                    dp[i][j] = ((dp[i-1][j-1])%2000000007+(dp[i-1][j])%2000000007)%2000000007;
                }
            }
        }
        return dp[n][r];
    }
    int uniquePaths(int m, int n) {
        return nCr(n+m-2,m-1);
    }
    
};