class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
         for(int i=0;i<n;i++){
            temp.push_back(nums[i]);
        }
        vector<int>ans(2*n);
        stack<int> s;
        for(int i=2*n-1;i>=0;i--){
            while(!s.empty() && temp[i]>=s.top()) s.pop();
            if(s.empty()) ans[i]=-1;
            else ans[i]=s.top();
            s.push(temp[i]);
        }
        ans.resize(n);
        return ans;
    }
};