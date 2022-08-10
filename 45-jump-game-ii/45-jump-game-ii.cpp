class Solution {
public:
//    int f(int ind){
//         if (ind>=n){
//             return INT_MAX;
//         }
//        int j=arr[ind];int jump=INT_MAX;
//         while(j--){
            
//             if(j+ind<n)  jump=min(jump,f(ind+j));
            
//         }
      
//     }
    int jump(vector<int>& nums) {
        int jumps=0;
        int maxreach=0;
        int curmax=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+i>maxreach) maxreach=nums[i]+i;
            if(curmax==i){
                jumps++;
                curmax=maxreach;
            }
        }
        return jumps;
    }
};