class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int prev_ind=0;prev_ind<=i-1;prev_ind++){
                if(pairs[i][0]>pairs[prev_ind][1] && 1+dp[prev_ind]>dp[i]){
                    dp[i]=1+dp[prev_ind];
                }
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};