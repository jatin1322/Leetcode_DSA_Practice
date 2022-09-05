class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int n=s.size();
        if(n<3) return 0;
       char a=s[0],b=s[1],c=s[2];
        int cnt;
        if(a!=b and b!=c and c!=a){
            cnt=1;
        }
        else cnt=0;
        for(int i=3;i<n;i++){
            a=b;
            b=c;
            c=s[i];
           if(a!=b and b!=c and c!=a){
            cnt++;
        } 
        }
        
       

        
        return cnt;
        
    }
};