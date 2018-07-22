class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		DFS(0,0,board);
	}
	bool DFS(int i,int j,vector<vector<char>>& board){
		if(i==9) return true;
		if(j==9) return DFS(i+1,0,board);
		if(board[i][j]=='.'){
			//=
			for(int p=1;p<10;p++){
				board[i][j]='0'+p;
				if(isValid(i,j,board)){
					if(solveSudokuDFS(i, j + 1,board)) return true;//bug 0
				}
				board[i][j]='.';
			}
			
		}
		else return DFS(i, j+1, board);
		return false;
	}
	bool isValid(int x,int y,vector<vector<char>>& board){
		for(int i=0;i<9;i++){
			if(board[i][y]==board[x][y]&&i!=x) return false;
		}
		for(int j=0;j<9;j++){
			if(board[x][j]==board[x][y]&&j!=y) return false;
		}
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				int nx=x/3*3+i;
				int ny=y/3*3+j;
 				if(board[x][y]==board[nx][ny] && (nx!=x||ny!=y)) return false;
			}
		}
		return true;
	}
};
/*
### DFS
- return value is worthy;
- the tiny question pop out, you shouldn't ignore;
- DFS need to ensure get the right answer, so it must turn back if it's wrong.
  It's also a curse to me.
*/