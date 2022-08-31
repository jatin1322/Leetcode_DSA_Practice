//Using DFS
class Solution {
public:
    bool dfs(int v, vector<int> adj[], vector<bool> &vis, vector<bool> &currVis, stack<int> &st)
    {
        vis[v] = true, currVis[v] = true;
        
        for(auto u: adj[v])
        {
            if(vis[u] == false)
            {
                if(dfs(u, adj, vis, currVis, st))   // there is cycle
                    return true;
            }
            else if(currVis[u] == true)   //if both vis and currVis are true
                return true;
        }
        
        st.push(v);
        currVis[v] = false;  //if no further nodes found trace back by making currVis false to show that the node has already been checked for cycle 
        return false;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& req)  //pahle wala bool tha, topo sort order
    {
        vector<int> topo;
        stack<int> st;       // stack used to store courses in decreasing order of dependencies
        vector<int> adj[n];
        vector<bool> vis(n, false), currVis(n, false);
        
        for(auto i: req)               //adj list
            adj[i[1]].push_back(i[0]);
        
        for(int i=0; i<n; i++)
        {
            if(vis[i] == false)
            {
                if(dfs(i, adj, vis, currVis, st))  //if cycle, all courses not possible, return empty vector
                {
                    topo.clear();
                    return topo;
                }
            }
        }
        while(!st.empty())  //if no cycle then return courses in order
        {
            topo.push_back(st.top());
            st.pop();
        }
        
        return topo;
    }
};

// class Solution {
// public:
//     vector<int> findOrder(int n, vector<vector<int>>& pr) {
        
//             vector<vector<int>> adj(n,vector<int>());
//         vector<int> indegree(n,0);
//         vector<int> topo;
//         for(int i=0; i<pr.size();i++){
//             adj[pr[i][1]].push_back(pr[i][0]);
//             indegree[pr[i][0]]++;
//         }
//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(indegree[i]==0){q.push(i); topo.push_back(i);}
//         }
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             for(auto it:adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0){
//                     q.push(it);
//                     topo.push_back(it);
//                 }
//             }
//         }
//         if(topo.size()==n) return topo;
//         else {topo.clear(); return topo;}
        
        
//         }
    
// };