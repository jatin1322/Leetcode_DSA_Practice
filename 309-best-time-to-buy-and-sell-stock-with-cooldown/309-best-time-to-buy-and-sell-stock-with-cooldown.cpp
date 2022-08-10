class Solution {
public:
     int solve(int ind,int buy,vector<int> &arr,vector<vector<int>> &dp){
      
        if(ind>=arr.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit;
        if(buy==0){
           profit=max(solve(ind+1,0,arr,dp),solve(ind+1,1,arr,dp)-arr[ind]); 
        }
        if(buy==1) profit=max(arr[ind]+solve(ind+2,0,arr,dp),solve(ind+1,1,arr,dp));
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};