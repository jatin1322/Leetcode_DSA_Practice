class Solution {
public:
    int solve(int ind,int n,string &s,vector<int> &dp){
        if(s[ind]=='0') return 0;
       
        if(ind>=n-1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int on=solve(ind+1,n,s,dp);
        int tw=0;
        if( ind< n-1 && (s[ind]=='1'|| (s[ind]=='2'&& s[ind+1]<'7'))) tw += solve(ind+2,n,s,dp);
        

        return dp[ind]=on+tw;
            
    }
    int numDecodings(string s) {
        int n=size(s);
        vector<int> dp(n+1,-1);
        return solve(0,s.size(),s,dp);
    }
};