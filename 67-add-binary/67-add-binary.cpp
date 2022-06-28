class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        if(n>m){
          for(int i=0;i<n-m;i++){
              b="0"+b;          }
        }
        else if(m>n){
             for(int i=0;i<m-n;i++){
              a="0"+a;         
             }
        }
        int c=max(n,m);
       int carry=0;
          string s="";
         
        
            for(int i=c-1; i>=0;i--){
                if(a[i]=='0' && b[i]=='0'){
                  if(carry) { s="1"+s; carry=0;}
                    else s="0"+s;
                }
                 if(a[i]=='1' && b[i]=='0'){
                     if(carry) { s="0"+s; }
                    else s="1"+s;
                }
                 if(a[i]=='0' && b[i]=='1'){
                  if(carry) { s="0"+s; }
                    else s="1"+s;
                } 
                if(a[i]=='1' && b[i]=='1'){
                    
                    if(carry) { s="1"+s; }
                    else {s="0"+s ; carry=1;}
                }
                
            }
        if(carry)s="1"+s;
        return s;
    }
};