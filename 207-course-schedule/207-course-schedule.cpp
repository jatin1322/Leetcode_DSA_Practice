class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pr) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0);
        vector<int> topo;
        for(int i=0; i<pr.size();i++){
            adj[pr[i][1]].push_back(pr[i][0]);
            indegree[pr[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){q.push(i); topo.push_back(i);}
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                    topo.push_back(it);
                }
            }
        }
        return topo.size()==n;
        
        }
};