class Solution {
public:
    int solve(int ind,int prev_ind,int &n,vector<int>& num,vector<vector<int>> &dp){
        if(ind==n+1) return 0;
        if(dp[ind][prev_ind]!=-1) return dp[ind][prev_ind];
        int nottake=solve(ind+1,prev_ind,n,num,dp);
        int take=1e-9;
        if(prev_ind==0 || num[ind-1]>num[prev_ind-1]){
             take=1+solve(ind+1,ind,n,num,dp);
        }
        return dp[ind][prev_ind]=max(take,nottake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        
        return solve(1,0,n,nums,dp);
        
    }
};