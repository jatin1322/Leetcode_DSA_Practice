class Solution {
public:
//     int solve(int ind,int target,vector<int> &arr){
//      //  if(target==0) return 0;
//         if(ind==0 ){
//           if(target%arr[0])  return 1e9;
//               else return target/arr[ind];
            
//         }  
//            int nottake=solve(ind-1,target,arr);
//             int take=1e9;
//           if(target>=arr[ind])  int take=1+solve(ind,target-arr[ind],arr);

//         return min(take,nottake);
        
//     }
    int minimumElementsUtil(vector<int>& arr, int ind, int T, vector<vector<int>>& dp){

    if(ind == 0){
        if(T%arr[0] == 0) return T/arr[0];
        else return 1e9;
    }
    
    if(dp[ind][T]!=-1)
        return dp[ind][T];
        
    int notTaken = 0 + minimumElementsUtil(arr,ind-1,T,dp);
    
    int taken = 1e9;
    if(arr[ind] <= T)
        taken = 1 + minimumElementsUtil(arr,ind,T-arr[ind],dp);
        
    return dp[ind][T] = min(notTaken,taken);
}


    int coinChange(vector<int>& arr, int T) {
           int n= arr.size();
    
    vector<vector<int>> dp(n,vector<int>(T+1,-1));
    int ans =  minimumElementsUtil(arr, n-1, T, dp);
    if(ans >= 1e9) return -1;
    return ans;

    }
};