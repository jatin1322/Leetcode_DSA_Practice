class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int n=v.size();
        int ans=0;
        map<int,int> m;
        m[0]++;
        for(int i=0; i<n; i++){
            ans=ans+v[i];
            int a=ans%k;
            if(a<0) a=a+k;
            m[a]++;
            
        }
        int ans1=0;
        for(auto x:m){
            int c=x.second;
            
           if(c>1) {ans1=ans1+(c*(c-1))/2;}
        }
        return ans1;
    }
};