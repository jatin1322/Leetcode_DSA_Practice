class Solution {
public:
    int maxcross(int l,int m,int h,vector<int> &arr){
         int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
 
    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
        return max(left_sum + right_sum - arr[m], max(left_sum, right_sum));
    }
    int solve(int l,int h,vector<int> &nums){
        if(l>h) return INT_MIN;
        if(l==h) return nums[l];
        int m=(l+h)/2;
        return max(max(solve(l, m - 1,nums),
               solve(m + 1, h,nums)),
               maxcross(l, m, h,nums));
    }
    int maxSubArray(vector<int>& nums) {
       return solve(0,nums.size()-1,nums);
        
        
    }
};