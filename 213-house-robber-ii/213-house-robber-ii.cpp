class Solution {
public:
     int a(int ind,vector<int>&dp,vector<int>&nums){
       
        if(ind==0)return nums[ind];
        if(ind<0)return 0;
         if(dp[ind]!=-1)return dp[ind];
        int pick=nums[ind]+a(ind-2,dp,nums);
        int nonpick=0+a(ind-1,dp,nums);
        return dp[ind]=max(pick,nonpick);
        
    }
    
    int rob1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n);
        if(n==2) return max(nums[0],nums[1]);
     //   return a(n-1,dp,nums);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i];
           if(i>1)  pick+=dp[i-2];
            int nonpick=dp[i-1];
            dp[i]=max(pick,nonpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        vector<int> temp1;
                vector<int> temp2;
        int n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1)  temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
        
        
    }
};