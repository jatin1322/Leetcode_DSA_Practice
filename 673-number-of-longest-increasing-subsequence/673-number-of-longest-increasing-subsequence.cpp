class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
         int n=arr.size();
        
        vector<int> dp(n,1);
       vector<int> count(n,1);
        for(int i=0;i<n;i++){
            
            for(int prev_index=0;prev_index<=i-1;prev_index++){
                if(arr[i]>arr[prev_index] )
                    if(1+dp[prev_index]>dp[i]){
                    dp[i]=1+dp[prev_index];
                   count[i]=count[prev_index];
                }
                else if(1+dp[prev_index]==dp[i]){
                    count[i]+=count[prev_index];
                }
                
            }
        }
       
        int ans=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                
            }
        }
int co = 0;
 
  //Traverse dp_l and dp_c
  // simultaneously
  for(int i = 0; i < n; i++)
  {
    //Update the count
    if (dp[i] == ans)
      co += count[i];
  }
   
  //Return the count of LIS
  return co;
    }
};