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
    
    vector<vector<int>> dp(n,vector<int>(T+1,0));
   // int ans =  minimumElementsUtil(arr, n-1, T, dp);
    for(int i=0;i<=T;i++){
       if(i%arr[0]==0) dp[0][i]=1;
        
    }
        for(int i=1; i<n;i++){
            for(int j=0;j<=T;j++){
                int nottaken=dp[i-1][j];
                int taken=0;
                if(arr[i]<=j){
                    taken=dp[i][j-arr[i]];
                }
                dp[i][j]=taken+nottaken;
            }
        }
    return dp[n-1][T];

    }
};