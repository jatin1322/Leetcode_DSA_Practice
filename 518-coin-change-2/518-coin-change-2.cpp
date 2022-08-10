class Solution {
public:
       int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(ind == 0){
        return (T%arr[0] == 0) ;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
    int taken = 0;
    if(arr[ind] <= T)
        taken = minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = notTaken+taken;
           // return dp[ind][T] = notTaken;
}


    int change(int T,vector<int>& arr) {
           int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, T, dp);
    
    return ans;

    }
};