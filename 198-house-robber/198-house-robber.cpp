class Solution {
public:
    int a(int ind,vector<int>&dp,vector<int>&nums){
       
        if(ind==0)return nums[ind];
        if(ind<0)return 0;
         if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+a(ind-2,dp,nums);
        int nonpick=0+a(ind-1,dp,nums);
        return dp[ind]=max(pick,nonpick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return a(n-1,dp,nums);
    }
};