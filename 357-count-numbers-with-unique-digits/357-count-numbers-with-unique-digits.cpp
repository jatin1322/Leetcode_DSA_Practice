class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        if(n==2) return 91;
        int a=9;
        for(int i=9;i>=11-n;i--){
            a*=i;
        }
        return a+countNumbersWithUniqueDigits(n-1);
    }
};