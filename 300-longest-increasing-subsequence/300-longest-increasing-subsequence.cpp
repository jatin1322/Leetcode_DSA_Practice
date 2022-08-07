class Solution {
public:
  
    int lengthOfLIS(vector<int>& nums) {
  vector<int> temp;
        int n=nums.size();
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                len++;
                temp.push_back(nums[i]);
            }
            else{
                int a=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[a]=nums[i];
            }
        }
        return len;
    }
};