class Solution {
public:
    int nextGreaterElement(int n) {
        
     string s="";
        int m=n;
        while(m){
            s+=(char)48+(m%10);
            m=m/10;
        }
        int i;
        reverse(s.begin(),s.end());
for( i=s.size()-2;i>=0;i--){
   if(s[i]<s[i+1]) break;
    }
        if(i==-1) return -1;
        
         sort(s.begin()+1+i,s.end());
       // cout<<s<<"  ";
        int j=i+1;
       for (int j = i + 1; j < s.length(); j++) {
            if (s[j] > s[i]) {
                swap(s[i], s[j]);
                break;
            }
        }

      
        long long ans=0;
        for(int i=0;i<s.size();i++){
            ans=ans*10+(int)s[i]-48;
        }
       // cout<<ans;
         if(ans==n || ans>INT_MAX)    
       { return -1;}
        else return (int)ans;
    }
};