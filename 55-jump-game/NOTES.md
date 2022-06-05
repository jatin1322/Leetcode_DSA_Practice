the only villiam here is 0 so if we able to skip 0's then we will able to reach last element
so just keep track of maximum reachable point ;
this code also works
```
class Solution {
public:
bool canJump(vector<int>& nums) {
int i, minjump = 0;
for(i = nums.size()-2; i >= 0; i--){
minjump++;
if(nums[i] >= minjump)
minjump = 0;
}
if(minjump == 0)
return true;
else
return false;
}
};
```