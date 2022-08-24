class Solution {
public:
    void solve(int ind,int target,vector<int> &arr,vector<int> &temp,vector<vector<int>> &ans){
      if(target==0){
            ans.push_back(temp);
            return;
        }
        if(ind>=arr.size()){
            if(target==0)
            ans.push_back(temp);
            return;
        }
    if(target>=arr[ind]){ temp.push_back(arr[ind]);
           solve(ind+1,target-arr[ind],arr,temp,ans);
       
        
        temp.pop_back();}
        // not pick
        int a=upper_bound(arr.begin(),arr.end(),arr[ind])-arr.begin();
        
        solve(a,target,arr,temp,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       
         vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solve(0,target,nums,temp,ans);
        return ans;
    }
};