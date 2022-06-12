class Solution {
public:
    void per(set<vector<int>> &ans,vector<int>& nums,int l,int r){
        
        if(l==r){
          //  sort(nums.begin(),nums.end());
            ans.insert(nums);
            return;
        }
        
        
        for(int i=l ; i<=r;i++){
             
            swap(nums[l],nums[i]);
            per(ans,nums,l+1,r);
            
             swap(nums[l],nums[i]);
            
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     
        set<vector<int>> ans;
        
        per(ans,nums,0,nums.size()-1);
             
        vector<vector<int>> ans1;
for(auto x: ans){
    ans1.push_back(x);
}
        return ans1;
        
    }
};