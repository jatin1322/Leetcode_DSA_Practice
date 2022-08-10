class Solution {
public:
    int solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
        if(ind==0){
            return 1;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int nottake=solve(ind-1,target,arr,dp);
        int take=(int)1e-9;
        if(target>=arr[ind]){
            take=arr[ind]*solve(ind,target-arr[ind],arr,dp);
        }
        return dp[ind][target] =max(take,nottake);
    }
    int integerBreak(int n) {
        vector<int> temp(n-1);
        for(int i=0;i<=n-2;i++){
            temp[i]=i+1;
        }
        vector<vector<int>> dp(n-1,vector<int> (n+1,-1)) ;
        return solve(n-2,n,temp,dp);
    }
};