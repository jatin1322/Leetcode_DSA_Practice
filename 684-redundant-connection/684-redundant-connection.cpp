class Solution {
public:
    bool dfs(vector<int> adj[],vector<int> &vis,int cur,int par=-1){
        if(vis[cur]) return true;
        vis[cur]=1;
        for(auto it:adj[cur]){
            if(dfs(adj,vis,it,cur) && it!=par) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> adj[n+1];
        vector<int> vis(n+1,false);
        for(auto it:edges){
            fill(vis.begin(),vis.end(),false);
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
            if(dfs(adj,vis,it[0])) return it;
        }
        return { };
    }
 };