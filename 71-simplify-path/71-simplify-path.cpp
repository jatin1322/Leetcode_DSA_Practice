class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
         stack<string> st;
        string res;
       for(int i=0; i<n; i++ ){
           if(path[i]=='/') continue;
           string a;
           while(path[i]!='/' && i<n) {a+=path[i]; i++;}
           if(a==".") continue;
           else if(a!="..") st.push(a);
           else if(!st.empty()) st.pop();
           }
        while(!st.empty()){
            res="/"+st.top()+res;
            st.pop();
        }
        if(res.size()==0){
            return "/";
        }
        return res;
    }
};