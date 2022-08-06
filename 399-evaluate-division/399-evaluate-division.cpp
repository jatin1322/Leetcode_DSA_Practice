class Solution {
public:

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
            int n=eq.size();
           unordered_map<string,vector<pair<string,double>>> mp;
        for(int i=0;i<n;i++){
            mp[eq[i][0]].push_back({eq[i][1],val[i]});
            mp[eq[i][1]].push_back({eq[i][0],1/val[i]});
            
        }
        int m=q.size();
        vector<double> ans(m);
        int i=0;
        while(i<m){
            
          
            string src=q[i][0];
            string end=q[i][1];
            if(mp.find(src)==mp.end() || mp.find(end)==mp.end()) {
                ans[i]=-1.0;
                
            }
            else{
                
               unordered_map<string,int> vis;
                queue<pair<string,double>> ss;
                ss.push({src,1});
                double score=1;
                vis[src]=1;
                while(!ss.empty())
                {      
                    auto qw=ss.front();
                         ss.pop();
                    string s=qw.first;
                    double score=qw.second;
                    
                 if(s==end) {ans[i]=score; break;}
                    for(auto it:mp[s]){
                    if(vis.find(it.first)!=vis.end()) continue;
                        double cur=score*it.second;
                        ss.push({it.first,cur});
                        
                        vis[it.first]=1;
                    
                    
                }
                }
              if(ans[i]==0)  ans[i]=-1;
                
                vis.clear();
                while(!ss.empty()) ss.pop();
                
                
                
                
        
                
                
                
            }
            i++;
        }
           
        
        
        
        return ans;
    }
};