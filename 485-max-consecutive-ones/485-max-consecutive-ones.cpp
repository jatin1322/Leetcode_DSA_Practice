class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) maxi++;
            else{
                ans=max(ans,maxi);
                maxi=0;
            }
        }
        ans=max(ans,maxi);
        return ans;
    }
};