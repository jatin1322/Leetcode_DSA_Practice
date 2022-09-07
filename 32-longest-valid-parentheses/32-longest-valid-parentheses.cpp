class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        if(n<=1) return 0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') left++;
            if(s[i]==')') right++;
            if(left==right){
                maxlen=max(maxlen,2*left);
            }
            if(right>left){
                right=left=0;
            }
        }
        right=left=0;   
        for(int i=n-1;i>=0;i--){
            if(s[i]=='(') left++;
            if(s[i]==')') right++;
            if(left==right){
                maxlen=max(maxlen,2*left);
            }
            if(left>right){
                right=left=0;
            }
        }
        return maxlen;
    }
};