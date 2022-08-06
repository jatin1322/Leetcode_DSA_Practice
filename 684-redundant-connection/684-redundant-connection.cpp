class Solution {
public:
    int find(int node,vector<int> &par){
        if(node==par[node]) return node;
        return par[node]=find(par[node],par);
    }
   bool unionn(int x,int y,vector<int> &par,vector<int> &rank){
       int xp=find(x,par);
       int yp=find(y,par);
       if(xp==yp) return false;
       if(rank[xp]>rank[yp]){
           par[yp]=xp;
       }
       else if(rank[yp]>rank[xp]){
           par[xp]=yp;
           
       }
       else{
           par[xp]=yp;
           rank[yp]++;
           return true;
          
       }
       return true;
   }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        
     vector<int> par(n+1,0);
        vector<int> rank(n+1,0);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
        
        for(auto it:edges){
            if(!unionn(it[0],it[1],par,rank)) return it;
                
        }
        return { };
    }
 };