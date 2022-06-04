class Solution {
public:
    
    bool a(vector<vector<char>>& board, int i, int j,string s, int k){
        if(k==s.size()){ return true;}
        if (i<0 || j<0 || i == board.size() || j == board[i].size()) return false;
        if (board[i][j] != s[k]) return false;
        board[i][j] = '*';
	bool exist = a(board, i, j+1, s, k+1)
		|| a(board, i, j-1, s, k+1)
		|| a(board, i+1, j, s, k+1)
		|| a(board, i-1, j, s, k+1);
	board[i][j] = s[k];
	return exist;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
          for(int i=0; i<n;i++){
           for(int j=0; j<m;j++){
           if(a(board,i,j,word,0)) return true;
               
                 } 
             }
    return false;
    }
};