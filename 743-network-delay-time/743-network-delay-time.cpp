class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
     vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
            
        }
        
        vector<int> dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int distt=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(pair<int, int> it:adj[prev]){
                int next=it.first;
                int nextdist=it.second;
                if(dist[next]>dist[prev]+nextdist){
                    dist[next]=dist[prev]+nextdist;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<dist.size();i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
            
        }
        return ans;
    } 
    
};