class Solution {
public:
    bool isValid(string s) {
   stack<char> st;
       st.push('a'); 
        for(int i=0; i<s.size() ;){
            if(st.top()=='(' && s[i]==')'){
                st.pop();
                i++;
               
            }
            else  if(st.top()=='{' && s[i]=='}'){
                st.pop();
                  i++;
            }
           else   if(st.top()=='[' && s[i]==']'){
                st.pop();
                  i++;
            }
            
        else   if(s[i]=='(' || s[i]=='{' || s[i]=='[')
           {
               st.push(s[i]);
               i++;
           }
            else{
                return false;
            }
         
        }
        cout<<st.size();
        if(st.size()==1){
            return true;
        }
        else{
            return false;
        }
        
        
    }
};