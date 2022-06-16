class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
      
        int e=0;
        while(s[e]==' '){
            e++;
        }
        vector <string> v;
        int i;
        for(i=e; i<n;i++){
           if(s[i]!=' ') {
               string a="";
           while(s[i]!=' ' && i<n)
           {
               a+=s[i];
               i++;
           } 
            v.push_back(a);
                 }
            
        }
     //   for(auto x:v)cout<<x<<" ";
        string ans="";
        for(int i=v.size()-1;i>=0;i--){
           for(int j=0;j<v[i].size();j++){
            ans+=v[i][j];
        }
          if(i!=0) ans+=" ";
        } 
        return ans;
    }
};