class Solution {
public:
    int maxScore(vector<int>& v, int k) {
         int n=v.size();
        int a=0;
        for(int i=n-k; i<n;i++){
            a=a+v[i];
        }
        int b=a;
        
        for(int i=0; i<k; i++){
            b=b-v[n-k+i];
            b=b+v[i];
            a=max(a,b);
        }
        return a;
    }
};