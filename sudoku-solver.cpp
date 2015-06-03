#include<iostream>
#include<vector>

using namespace std;

class Solution {
	private:
		int colsFlag[9];
		int rowsFlag[9];
		int gridsFalg[9];
	public:
		bool isValidate(vector<vector<char> >& board,int x,int y){
			for(int i=0;i<9;++i){
				if(i!=x && (1<<board[x][y]) & colsFlag[i])
					return false;
				if(i!=y && (1<<board[x][y]) & rowsFlag[i])
					return false;
			}
			int startColume = (x / 3) * 3;
			int startRow = (y / 3) * 3;
			for(int i=0;i<3;++i){
				for(int j=0;j<3;++j){
					if(startColume+i!=x && startRow+j!=y && board[startColume+i][startRow+j]==board[x][y])
						return false;
				}
			}
			return true;
		}

		bool btrack(vector<vector<char> >& board,int col,int row){
			if(row == 9)	return true;
			if(col == 9)
				return btrack(board,0,row+1);
			if(board[col][row] != '.')
				return btrack(board,col+1,row);
			for(int number = 1 ; number < 10 ; ++number){
				board[col][row] = number + '0';
				if(isValidate(board,col,row) && btrack(board,col+1,row))
					return true;
				board[col][row] = '.';
			}
		}
			
		void solveSudoku(vector<vector<char> >& board) {
			btrack(board,0,0);
		}
};
int main(){
	char c0[10] = "..9748...";
	char c1[10] = "7........";
	char c2[10] = ".2.1.9...";
	char c3[10] = "..7...24.";
	char c4[10] = ".64.1.59.";
	char c5[10]= ".98...3..";
	char c6[10]= "...8.3.2.";
	char c7[10]= "........6";
	char c8[10]= "...2759..";
	vector<vector<char> > board;
	board.push_back(vector<char>(c0,c0+9));
	board.push_back(vector<char>(c1,c1+9));
	board.push_back(vector<char>(c2,c2+9));
	board.push_back(vector<char>(c3,c3+9));
	board.push_back(vector<char>(c4,c4+9));
	board.push_back(vector<char>(c5,c5+9));
	board.push_back(vector<char>(c6,c6+9));
	board.push_back(vector<char>(c7,c7+9));
	board.push_back(vector<char>(c8,c8+9));

	for(int i=0;i<board.size();++i){
		for(int j=0;j<board[0].size();++j){
			cout<<board[i][j]<<"  ";
		}
			cout<<endl;
	}
	Solution s;
	s.solveSudoku(board);
	cout<<endl;
	for(int i=0;i<board.size();++i){
		for(int j=0;j<board[0].size();++j){
			cout<<board[i][j]<<"  ";
		}
			cout<<endl;
	}
}
