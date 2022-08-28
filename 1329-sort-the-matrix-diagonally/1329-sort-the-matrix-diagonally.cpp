class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
      
        int n=mat.size();
        int m=mat[0].size();
        for(int q=0;q<n;q++){
            
       for(int k=m-1;k>=0;k--){
             vector<int> temp;
        int i=q;
        int j=k;
        while(i<n && j< m){
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }
           sort(temp.begin(),temp.end());
           int l=0;
            i=q;
           j=k;
        while(i<n && j< m){
            mat[i][j]=temp[l];
            l++;
            i++;
            j++;
        }
           
        }
            
        }
        
        return mat;
        
        
        
        
        
        
        
        
        
        
        
        
    }
};