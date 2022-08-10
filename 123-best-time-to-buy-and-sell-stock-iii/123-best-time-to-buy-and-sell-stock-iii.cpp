class Solution {
public:
    int solve(int ind,int buy,int cap,vector<int> &arr,vector<vector<vector<int>>> &dp){
       if(cap==0) return 0;
        if(ind==arr.size()) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit;
        if(buy==0){
           profit=max(solve(ind+1,0,cap,arr,dp),solve(ind+1,1,cap,arr,dp)-arr[ind]); 
        }
        else profit=max(arr[ind]+solve(ind+1,0,cap-1,arr,dp),solve(ind+1,1,cap,arr,dp));
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (3,-1)));
        
        return solve(0,0,2,prices,dp);
    }
};