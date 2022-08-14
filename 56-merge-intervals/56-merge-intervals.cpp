class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int n=arr.size();
        int m=arr[0].size();
        int l=arr[0][0]; int r=arr[0][1];
        for(int i=1;i<n;i++){
            if(arr[i][0]>=l && arr[i][1] <= r){
                l=min(l,min(arr[i][0],arr[i-1][0]));
                r=max(r,max(arr[i][1],arr[i-1][1]));
            }
           else if(arr[i][0]<=r){
                l=min(l,min(arr[i][0],arr[i-1][0]));
                r=max(r,max(arr[i][1],arr[i-1][1]));
               
            }
            
            else{
              ans.push_back({l,r});
                
                         l=arr[i][0];  r=arr[i][1];
                
            }
        }
      ans.push_back({l,r});
        return ans;
    }
};