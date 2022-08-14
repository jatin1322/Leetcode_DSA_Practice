class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumSoFar=0;
        int maxSumSoFar=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sumSoFar+=nums[i];
            if(maxSumSoFar<sumSoFar){
                maxSumSoFar=sumSoFar;
            }
            if(sumSoFar<0){
                sumSoFar=0;
            }
        }
        return maxSumSoFar;
        
        
    }
};