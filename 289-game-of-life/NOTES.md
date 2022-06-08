if(i>0 && j>0) {
if(curr[i-1][j-1] == 1) liveNeighbours++;
}
if(i>0 && j<n-1) {
if(curr[i-1][j+1] == 1) liveNeighbours++;
}
if(i<m-1 && j>0) {
if(curr[i+1][j-1] == 1) liveNeighbours++;
}
if(i<m-1 && j<n-1) {
if(curr[i+1][j+1] == 1) liveNeighbours++;
}
return liveNeighbours;
}
void gameOfLife(vector<vector<int>>& board) {
vector<vector<int>> curr = board;
int m = board.size();
int n = board[0].size();
for(int i = 0; i<m; i++) {
for(int j = 0; j<n; j++) {
int ln = getLiveNeighbours(curr, i, j, m, n);
if(board[i][j] == 0) {
//currently dead
//can become alive if has exactly three live neighbours
if(ln == 3) {
board[i][j] = 1;
}
}
else if(board[i][j] == 1) {
//<2 -> die
//==2 || ==3 live
//>3 ->die
if(ln < 2 || ln > 3) {
board[i][j] = 0;
}
}
}
}
}
};
```