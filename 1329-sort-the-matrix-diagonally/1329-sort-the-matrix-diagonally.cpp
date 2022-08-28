class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      
        int n=mat.size();
        int m=mat[0].size();
        
       
            
       for(int k=0;k<m;k++){
             vector<int> temp;
        int i=0;
        int j=k;
        while(i<n && j< m){
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
           sort(temp.begin(),temp.end());
           int l=0;
            i=0;
           j=k;
        while(i<n && j< m){
            mat[i][j]=temp[l];
            l++;
            i++;
            j++;
        }
           
        }
            
        
        for(int q=1;q<n;q++){
            
       
             vector<int> temp;
        int i=q;
        int j=0;
        while(i<n && j< m){
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
           sort(temp.begin(),temp.end());
           int l=0;
            i=q;
           j=0;
        while(i<n && j< m){
            mat[i][j]=temp[l];
            l++;
            i++;
            j++;
        }
           
        
            
        }
        
        return mat;
        
        
        
        
        
        
        
        
        
        
        
        
    }
};