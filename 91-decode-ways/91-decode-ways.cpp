class Solution {
public:
//     int solve(int ind,int n,string &s,vector<int> &dp){
//         if(s[ind]=='0') return 0;
       
//       //  if(ind>=n-1) return 1;
//        // if(dp[ind]!=-1) return dp[ind];
//         int on=solve(ind+1,n,s,dp);
//         int tw=0;
//         if( ind< n-1 && (s[ind]=='1'|| (s[ind]=='2'&& s[ind+1]<'7'))) tw += solve(ind+2,n,s,dp);
        

//         return dp[ind]=on+tw;
            
//     }
    int numDecodings(string s) {
        int n=size(s);
        if(n==0) return n;
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){dp[i]=0;continue;}
            dp[i]=dp[i+1];
        
        if( i< n-1 && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7'))) dp[i] += dp[i+2];
        }
        
        return dp[0];
    }
};