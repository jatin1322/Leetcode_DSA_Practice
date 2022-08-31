class Solution {
public:
    void dfsb(int i,int j,vector<vector<int> > &A,vector<vector<bool>> &blue,int prev,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || blue[i][j]==1 || A[i][j]<prev){
        return ;
    }
    
  
        blue[i][j]=1;
        dfsb(i,j-1,A,blue,A[i][j],n,m);
        dfsb(i,j+1,A,blue,A[i][j],n,m);
        dfsb(i+1,j,A,blue,A[i][j],n,m);
       dfsb(i-1,j,A,blue,A[i][j],n,m);
       
    
     return;
    
}
void dfsr(int i,int j,vector<vector<int> > &A,vector<vector<bool>> &red,int prev,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || red[i][j]==1 || A[i][j]<prev){
        return ;
    }
    
    
        red[i][j]=1;
        dfsr(i,j-1,A,red,A[i][j],n,m);
        dfsr(i,j+1,A,red,A[i][j],n,m);
        dfsr(i+1,j,A,red,A[i][j],n,m);
       dfsr(i-1,j,A,red,A[i][j],n,m);
      
    
   return;
    
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& A) {
         int n=A.size();
    int m=A[0].size();
    vector<vector<bool>> red(n,vector<bool> (m,false));
     vector<vector<bool>> blue(n,vector<bool> (m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && blue[i][j]==0){
               
                dfsb(i,j,A,blue,INT_MIN,n,m);
            }
            if(j==0 && blue[i][j]==0){
               
                dfsb(i,j,A,blue,INT_MIN,n,m);
            }
            if(i==n-1 && red[i][j]==0){
               
                 dfsr(i,j,A,red,INT_MIN,n,m);
            }
            if(j==m-1 && red[i][j]==0){
                
                 dfsr(i,j,A,red,INT_MIN,n,m);
            }
            
        }
    }
    vector<vector<int>>ans;
     for(int i=0;i<n;i++){
         
        for(int j=0;j<m;j++){
            
           if(red[i][j]==1 && blue[i][j]==1){
               vector<int> temp;
               temp.push_back(i);
               temp.push_back(j);
               ans.push_back(temp);  }
        }
    }

     return ans;
    }
};