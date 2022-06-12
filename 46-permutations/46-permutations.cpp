class Solution {
public:
    void per(vector<vector<int>> &ans,vector<int>& nums,int l,int r){
        
        if(l==r){
            ans.push_back(nums);
            return;
        }
        
        
        for(int i=l ; i<=r;i++){
             
            swap(nums[l],nums[i]);
            per(ans,nums,l+1,r);
            
             swap(nums[l],nums[i]);
            
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
       
        per(ans,nums,0,nums.size()-1);
        return ans;
        
    }
};