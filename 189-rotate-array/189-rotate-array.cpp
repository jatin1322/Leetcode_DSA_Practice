class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N=nums.size();
         int arr[N];
   for(int i=0;i<N;i++)
   {
       arr[i]=nums[i];
   }
    for(int i=0;i<N;i++)
       {   
           nums[(i+k)%N]=arr[i];
           
       }
     
    }
};