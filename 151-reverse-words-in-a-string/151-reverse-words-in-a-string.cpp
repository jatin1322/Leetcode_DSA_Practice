/* class Solution {
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
    
};*/
// in space complexity O(1);
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};
