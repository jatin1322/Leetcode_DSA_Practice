class Solution {
public:
 
    int lengthOfLongestSubstring(string s) {
        map<char,int> m;
        if(s.size()==0){
            return 0;
        }
        int j=0;
        int ans=-1;
        for(int i=0; i<s.size();i++){
            if(j<m[s[i]]){
                j=m[s[i]];
            }
            if(ans<i-j+1){
                ans=i-j+1;
            }
            
            m[s[i]]=i+1;
        }
        return ans;
    }
};