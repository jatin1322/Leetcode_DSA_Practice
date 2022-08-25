class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        
        long long low=1;
        long long high=x;
        
        long long guess;
        
        while(true){
            guess=low+(high-low)/2;
            if((guess*guess)>x){
                
                high=guess-1;
                
            }
            else {
                if(((guess+1)*(guess+1))>x) return guess; 
                low=guess+1;
                
            }
            
        }
        return (int)guess;
    }
};