class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int d) {
              int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
if((sum-d)&1 || d>sum) return 0;
    
        int k=(sum-d)/2;
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);
        //vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        //return solve(n-1,k,arr,dp);
      prev[0]=1;
        // for(int i=0;i<n;i++){
        //     dp[i][0]=1;
        // }
        if(arr[0]==0 ) prev[arr[0]]=2;
       else   prev[0]=1;
    if(arr[0]!=0 && arr[0]<=k) prev[arr[0]] = 1;
            for(int i=1;i<n;i++){
                
                for(int j=0;j<=k;j++){
                        int taken=0;
  if(j>=arr[i]) taken=prev[j-arr[i]];
    int nottaken=prev[j];
     curr[j]=(taken+nottaken)%1000000007;
                    
                }
                prev=curr;
                
                
            }
        
        return prev[k];
      
    }
};