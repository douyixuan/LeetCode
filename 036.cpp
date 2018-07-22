class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool ans=true;
		ans = ans & line(0,1,board);
		ans = ans & line(1,0,board);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				ans = ans&cube(i*3,j*3,board);
			}
		}
		return ans;
	}
	bool line(int x,int y,vector<vector<char>>& board){
		
		for(int i=0;i<9;i++){
			map<char,int> mao;
			for(int j=0;j<9;j++){
				int nx=(x==0?i:j);
				int ny=(x==0?j:i);
				char ch=board[nx][ny];
				if(ch!='.') mao[ch]++;
				if(mao[ch]>1) return false;
			}
		}
		return true;
	}
	bool cube(int x,int y,vector<vector<char>>& board){
		map<char,int> san;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				int nx=x+i;
				int ny=y+j;//bug
				char ch=board[nx][ny];
				if(ch!='.') san[ch]++;
				if(san[board[nx][ny]]>1) return false;
			}
		}
		return true;
	}
};
/*
- mix char and int type; and ignore the amount of '.' is large
- j mistake of i;
- logic is clear, then debug is easy.
*/