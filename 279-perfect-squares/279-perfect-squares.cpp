class Solution {
public:
//     int f(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
       
//         if(target==0) return 0;
//         if(ind==0) return target;
//         if(dp[ind][target]!=-1) return dp[ind][target];
//         int take=1e9;
//      if(target>=arr[ind]) take =1+f(ind,target-arr[ind],arr,dp);
//        // int nottake=1e9;
//         int nottake=f(ind-1,target,arr,dp);
//         return dp[ind][target]=min(take,nottake);
//     }
    
    
    
    int numSquares(int n) {
        vector<int> perfect;
        for(int i=0;i<n;i++){
            if(i*i<=n) perfect.push_back(i*i);
            else break;
        }
        int ind=perfect.size();
        vector<vector<int>> dp(ind,vector<int> (n+1,0));
        vector<int> prev(n+1);
        vector<int> curr(n+1);
        for(int i=0;i<ind;i++){
           
            for(int j=0;j<=n;j++){
                if(j==0){curr[j]=0; continue;}
                if(i==0) {curr[j]=j;continue;}
                 int take=1e9;
     if(j>=perfect[i]) take =1+curr[j-perfect[i]];
        
       int nottake=  prev[j];
         curr[j]=min(take,nottake);
                
            }
            prev=curr;
            
        }
        return prev[n];
    }
};