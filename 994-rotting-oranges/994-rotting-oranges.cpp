class Solution {
public:
    bool issafe(int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m) return true;
        else return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        int one=0;
       // vector<vector<bool>> vis(n,vector<bool> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){q.push({i,j});
                                // vis[i][j]=1;
                                 }
                if(grid[i][j]==1) one++;
            }
        }
        if(one==0) return 0;
        int mint=0;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                int i=q.front().first;
                int j=q.front().second;
               // vis[x][y]=1;
                
                q.pop();
                 if(issafe(i+1,j,n,m)  && grid[i+1][j]==1){
                     grid[i+1][j]=2;
                     q.push({i+1,j});
                     one--;
                 }
                if(issafe(i-1,j,n,m)  && grid[i-1][j]==1){
                     grid[i-1][j]=2;
                     q.push({i-1,j});
                    one--;
                 }
                if(issafe(i,j+1,n,m)  && grid[i][j+1]==1){
                     grid[i][j+1]=2;
                     q.push({i,j+1});
                    one--;
                 }
                if(issafe(i,j-1,n,m) && grid[i][j-1]==1){
                     grid[i][j-1]=2;
                     q.push({i,j-1});
                    one--;
                 }
                if(one==0) return mint+1;
            }
            mint++;
        }
        return -1;
    }
};