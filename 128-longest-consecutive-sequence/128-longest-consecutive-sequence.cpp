class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      if(nums.size()==0 || nums.size()==1) return nums.size();
        vector<int> s;
        
        unordered_map<int,int> m;
        for(int num:nums){
           if(m.find(num)==m.end())
            s.push_back(num);
            m[num]++;
        }
        sort(s.begin(),s.end());
        int n=s.size();
        if(n==1) return 1; 
        if(n==2 && s[0]+1==s[1]) return 2; 
        int count=0;
        int ans=0;
        
       for(int i=0;i<n-1;i++){
           if(s[i+1]==s[i]+1){
               count++;
              // cout<<"Sas";
           }
           else{
               
               ans=max(count+1,ans);
               count=0;
               
           }
       }
        
   if(s[n-1]==s[n-2]+1) ans=max(count+1,ans);

        return ans;
    }
};