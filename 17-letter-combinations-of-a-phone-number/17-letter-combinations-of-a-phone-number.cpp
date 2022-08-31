class Solution {
public:
    void solve(int i, string &digits,string &temp,vector<string> &ans,map<char,string> &m){
       
        if(temp.size()==digits.size() && temp.size()!=0) ans.push_back(temp);
        if(i>=digits.size()) return ;
       
        for(int j=0;j< m[digits[i]].size();j++){
         
            temp.push_back(m[digits[i]][j]); 
             solve(i+1,digits,temp,ans,m);
             temp.pop_back();
        }
        
       
        
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> ans;
        string temp;
        int i=0;
        solve(i,digits,temp,ans,m);
        
        return ans;
    }
};