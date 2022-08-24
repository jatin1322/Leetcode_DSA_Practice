class Solution {
public:
     bool ispalindrome(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
    
    void solve(int ind,string s,vector < string > &temp,vector < vector < string > > &ans){
        if(ind==s.size()){
            ans.push_back(temp);
            return ;
        }
        for(int j=ind;j<s.size();j++){
            if(ispalindrome(s,ind,j)){
                temp.push_back(s.substr(ind,j-ind+1));
                solve(j+1,s,temp,ans);
                temp.pop_back();
                
            }
        }
       

        
    }
    vector<vector<string>> partition(string s) {
        vector < vector < string > > res;
      vector < string > path;
      solve(0, s, path, res);
      return res;

    }
};