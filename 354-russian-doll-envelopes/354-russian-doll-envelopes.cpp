class Solution {
public:
   static bool comp(const vector<int> &v1,const vector<int> &v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }
        return v1[0]<v2[0];
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        
        sort(arr.begin(),arr.end(),comp);
        int n=arr.size();
        vector<int> dp;
        for(int i=0;i<n;i++){
          
            
                auto ind=lower_bound(dp.begin(),dp.end(),arr[i][1])-dp.begin();
                if(ind==dp.size()){
                    dp.push_back(arr[i][1]);
                }
                dp[ind]=arr[i][1];
                
        
        }
        return dp.size();
        
    }
};