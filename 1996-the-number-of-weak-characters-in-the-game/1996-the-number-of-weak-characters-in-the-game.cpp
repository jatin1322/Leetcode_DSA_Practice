class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        int n=p.size();
         vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<p.size();i++){
            a[i]=p[i][0];
            b[i]=p[i][1];
        }
        int ans=0;
        vector<int> gre(n);
        gre[n-1]=b[n-1];
        for(int i=n-2;i>=0;i--){
            gre[i]=max(gre[i+1],b[i]);
        }
        
        for(int i=0;i<n-1;i++){
            int x=upper_bound(a.begin(),a.end(),a[i])-a.begin();
            if(x==n) continue;
            if(gre[x]>b[i]){
                ans++;
            }
            
        }
        return ans; 
    }
};