class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> ans(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto it=q.front();
            int i=it.first;
            int j=it.second;
            q.pop();
            for(int k=0;k<4;k++){
                int newi=i+dir[k][0];
                int newj=j+dir[k][1];
                if(newi>=0 && newj>=0 && newi<n && newj<m){
                    if(ans[newi][newj]>ans[i][j]+1){
                        ans[newi][newj]=ans[i][j]+1;
                        q.push({newi,newj});
                    }
                }
            }
        }
        
        
        return ans;
    }
};