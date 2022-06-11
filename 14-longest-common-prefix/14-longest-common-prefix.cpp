class Solution {
public:
    bool a(vector<string>& strs,int j) {
        char q=strs[0][j];
     for(int i=1; i<strs.size() ; i++){
            if(strs[i][j]!=q){
                return false;
            }
        }
        return true;
        
    }
    string longestCommonPrefix(vector<string>& strs) {
       int count=INT_MAX;
        for(int i=0; i<strs.size() ; i++){
            if(strs[i].size()<count) count=strs[i].size();
            
        }
        int i=0;
        string ans="";
        while(i<count){
            if(a(strs,i)){ ans+=strs[0][i];
                i++;}
            else{
                
                return ans;
            }
        }
        return ans;
    }
};