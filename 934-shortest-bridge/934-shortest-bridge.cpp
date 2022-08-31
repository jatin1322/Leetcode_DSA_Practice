class Solution {
public:
void dfs(int i,int j, vector<vector<int>>&grid,vector<vector<int>>&vis){
    int n=grid.size()  ; 
    if(i<0 || i>=n || j<0 || j>=n) return;  
    if(grid[i][j]==0) return ; 
    if(vis[i][j]==1) return  ; 
    
    vis[i][j] = 1; 
    grid[i][j] = 8 ;  
    
    dfs(i+1,j,grid,vis)  ;
    dfs(i,j+1,grid,vis)  ;
    dfs(i-1,j,grid,vis)  ;
    dfs(i,j-1,grid,vis)  ;
}
int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size()  ; 
    int ok = 0 ; 
    vector<vector<int>>vis(n,vector<int>(n,0))  ; 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                dfs(i,j,grid,vis) ; 
                ok = 1 ; 
                break ; 
            }
        }
        if(ok) break ; 
    }
    
    vector<pair<int,int>>p1,p2 ;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==8) p1.push_back({i,j})  ;
            else if(grid[i][j]==1) p2.push_back({i,j})  ; 
        }
    }
    
    int mn = INT_MAX;  
    for(int i=0;i<p1.size() ; ++i){
        for(int j=0;j<p2.size() ; ++j){
            int k = abs(p1[i].first-p2[j].first)+abs(p1[i].second-p2[j].second)   ; 
            mn = min(mn,k) ; 
        }
    }
    
    return mn-1 ; 
}
};