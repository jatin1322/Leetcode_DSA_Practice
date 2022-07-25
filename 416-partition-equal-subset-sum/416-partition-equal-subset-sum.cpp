class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int sum=accumulate(arr.begin(),arr.end(),0);
        if(sum&1) return false;
        sum=sum/2;
        int k=sum;
   
     int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
                for(int i=0;i<n;i++){
                    dp[i][0]=1;
                } 
                               if(arr[0]<=k) dp[0][arr[0]]=1;
        for(int j=1;j<n;j++)
                               { for(int i=1;i<=k;i++){
                    
                    bool nontaken=dp[j-1][i];
                    bool taken=0;
                    if(arr[j]<=i){
                        taken=dp[j-1][i-arr[j]];
                    }
                    dp[j][i]=nontaken || taken;
                }
                               } 
                               return dp[n-1][k];
    }
};