class Solution {
public:
    int fib(int n) {
        int prev=0;
        int curr=1;
        if(n<=1) return n;
        
        for(int i=2;i<=n;i++){
            int ans=curr+prev;
             prev=curr;
             curr=ans;
        }
        return curr;
    }
};