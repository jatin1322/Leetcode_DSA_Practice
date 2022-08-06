class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    
        for(auto it:times){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        vector<int> dist(n+1,INT_MAX);
        vector<int> vis(n+1,0);
        vector<int>parent(n+1,-1);

        parent[k]=k;
        dist[k]=0;
        vis[k]=1;
  for(int i=0;i<adj[k].size();i++){
            pq.push({adj[k][i].second,adj[k][i].first});
            if(dist[k]+adj[k][i].second<dist[adj[k][i].first]){
                  dist[adj[k][i].first]=  dist[k]+adj[k][i].second;
                    parent[adj[k][i].first]=k;
                }
        }
        
        while(pq.empty()!=true){
           pair<int, int> cur=pq.top();
    pq.pop();
            // cout<<cur.second<<cur.first<<endl;
           if(vis[cur.second ]==0){
           
            for(int i=0;i<adj[cur.second].size();i++){
                // cout<<graph[cur.second][i].first<<endl;
                  if(vis[adj[cur.second][i].first]==0){
                if(dist[cur.second]+adj[cur.second][i].second<dist[adj[cur.second][i].first]){
                  dist[adj[cur.second][i].first]=  dist[cur.second]+adj[cur.second][i].second;
 pq.push({  dist[adj[cur.second][i].first],adj[cur.second][i].first});
                    parent[adj[cur.second][i].first]=cur.second;
                      }
                }
            }
            }
            vis[cur.second]=1;
        }
        int m=INT_MIN;
        for(int i=1;i<dist.size();i++){
            // cout<<dist[i]<<" ";
            if(m<dist[i]){
                m=dist[i];
            }
        }
        if(m!=INT_MAX){
            return m;
        }
        else{
            return -1;
        }

    } 
};