class Solution {
public:
    int trailingZeroes(int n) {
        long long int a=5;
    int ans=0;
        while(n/a){
            ans+=n/a;
            a=a*5;
        }
        return ans;
    }
};