class Solution {
public:
    // f(int ind){
    //     if(i=<2) return i;
    //     f(n-1)+f(n-2);
    // }
    int climbStairs(int n) {
        if(n<=2) return n;
        int prev1=1;
        int prev2=2;
        for(int i=3;i<=n;i++){
            int ans=prev1+prev2;
            prev1=prev2;
            prev2=ans;
        }
        return prev2;
    }
};