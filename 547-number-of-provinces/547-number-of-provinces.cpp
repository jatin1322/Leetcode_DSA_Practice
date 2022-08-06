class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& matrix) {
      int n=matrix.size();
        vector<int> adj[n+1];
       
       
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(matrix[i][j]==1){
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int ans=0;
        vector<int> vis(n+1);
        for(int i=1;i<=n;i++){
            if(!vis[i]){
              ans++;
                dfs(i,adj,vis);
            }
        }
        return ans;
    }
};