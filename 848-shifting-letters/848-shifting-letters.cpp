class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
    shifts[n-1]%=26;
        for(int i=n-2;i>=0;i--){
            shifts[i]+=shifts[i+1];
            shifts[i]%=26;
        }
        
        for(int i=0;i<n;i++){
            int a=122-s[i];
            if(a>=shifts[i]){
                s[i]=s[i]+shifts[i];
            }
            else{
                shifts[i]-=a;
                s[i]=96+shifts[i];
            }
            
            
        }
        return s;
    }
};