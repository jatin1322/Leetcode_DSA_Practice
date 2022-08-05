class Solution {
public:
    bool check(int node,vector<int> &color,vector<vector<int>> &v){
        if(color[node]==-1){
            color[node]=1;
        }
        for(auto it:v[node]){
            if(color[it]==-1){
                color[it]=1-color[node];
            
            if(!check(it,color,v)) return false;}
            else if(color[it]==color[node]) return false;
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(check(i,color,graph)==0){
                    return false;
                };
            }
            
            
        }
        return true;
    }
};