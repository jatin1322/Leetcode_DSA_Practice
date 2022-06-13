class Solution {
public:
 
       bool ispalindrome1(string s,int i,int j){
       while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            
            i++;
            j--;}
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        if(ispalindrome1(s,0,n-1)){
            return true;
        }
        else{
            int i=0;
            int j=s.size()-1; 
            while(i<j){
                if(s[i]!=s[j]){
                    return ispalindrome1(s,i,j-1) || ispalindrome1(s,i+1,j);
                }
                
                    i++;
                    j--;
                
            }
             
           return true;
                     
        }
    }
};