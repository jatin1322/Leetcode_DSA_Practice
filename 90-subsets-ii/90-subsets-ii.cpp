class Solution {
public:
    void solve(int ind,vector<int> &nums,vector<int> &temp,vector<vector<int>> &ans){
        //pick
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
     
           solve(ind+1,nums,temp,ans);
        temp.pop_back();
        int a=upper_bound(nums.begin(), nums.end(), nums[ind]) - nums.begin();

        solve(a,nums,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(0,nums,temp,ans);
        return ans;
    }
};