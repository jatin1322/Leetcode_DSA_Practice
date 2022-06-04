class Solution {
public:
    void ab(vector<int> &v,int a,int b,int c,int d,vector<vector<int>>& matrix,int & ans,int n){
        if(ans<=n){  v.push_back(matrix[a][c]); ans++;   }
       
        for(int i=c+1; i<d ; i++){
         if(ans<=n)  { v.push_back(matrix[a][i]); ans++;}
            
        }
       
         if(ans<=n && c<d){   v.push_back(matrix[a][d]); ans++;   }
        for(int i=a+1; i<b ; i++){
          
              if(ans<=n)  {  v.push_back(matrix[i][d]); ans++;}
        }
         if(ans<=n){     v.push_back(matrix[b][d]); ans++;   }
       
         for(int i=d-1; i>=c+1 ; i--){
           
              if(ans<=n)  {   v.push_back(matrix[b][i]); ans++;}
        }
          if(ans<=n && c<d){     v.push_back(matrix[b][c]); ans++;   }
         
         for(int i=b-1; i>=a+1 ; i--){
            
              if(ans<=n)  {  v.push_back(matrix[i][c]); ans++;}
        }
        
    }
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c1=matrix[0].size();
        
        int a=0;
        int b=r-1;
        int c=0;
        int d=c1-1;
        int ans=1;
        vector<int> v;
        int n=r*c1;
        if(r==1 || c1==1){
            if(r==1 && c1==1){
                v.push_back(matrix[0][0]);
                return v;
            }
           if(r==1){
               for(int i=0; i<c1 ; i++){
                    v.push_back(matrix[0][i]);
                }
                return v;
           } 
            else{
                for(int i=0; i<r ; i++){
                    v.push_back(matrix[i][0]);
                }
                return v;
            }
        }
        while(ans<=n){
            ab(v,a,b,c,d,matrix,ans,n);
            a++;
            b--;
            c++;
            d--;
        }
    
        return v;
    }
};