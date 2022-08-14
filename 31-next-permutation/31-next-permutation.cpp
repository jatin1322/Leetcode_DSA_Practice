class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i;
        for(i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                break;
            }
        }
        if(i==0){
            sort(nums.begin(),nums.end());
            
        }
      else{  sort(nums.begin()+i,nums.end());
      for(int j=i;j<n;j++){
          if(nums[i-1]<nums[j]){swap(nums[i-1],nums[j]);
                               break;}
      }
           }
        
    }
};