#include<iostream>
#include<vector>
using namespace std;

/*
 * 注意下标/3*3
 *
 * 能够加速下标的查重过程？
 */
class Solution {
    const int colNum = 9;
    const int rowNum = 9;
    const int subColNum = 3;
    const int subRowNum = 3;
    public:
        bool isValid(vector<vector<char> >&board,int col,int row) {
            if(board[col][row] == '.')
                return true;
            for(int idx=0;idx<colNum;++idx)
                if(idx != col && board[idx][row] == board[col][row])
                    return false;
            for(int idx=0;idx<rowNum;++idx)
                if(idx != row && board[col][row] == board[col][idx])
                    return false;
            for(int colIdx = (col/subColNum)*subColNum ; colIdx < (col/subColNum)*subColNum + 3 ;++colIdx) 
                for(int rowIdx = (row/subRowNum)*subRowNum ; rowIdx < (row/subRowNum)*subRowNum + 3;++rowIdx)
                    if(colIdx!=col && rowIdx!=row && board[colIdx][rowIdx]==board[col][row])
                        return false;
            return true;
        }

        bool isValidSudoku-simple(vector<vector<char> >& board) {
            for(int i=0;i<colNum;++i)
                for(int j=0;j<rowNum;++j) 
                    if( !isValid(board,i,j) )
                        return false;
            return true;
        }
        bool isValidSudoku(vector<vector<char> >& board) {
			//matrixExist的横坐标表示第几个矩形
			bool rowExist[9][9]={false}, colExist[9][9]={false}, matrixExist[9][9]={false};

			for(int col=0;col<board.size();++col) {
				for(int row=0;row<board[0].size();++row) {
					if(board[col][row] != '.') {
						int num = board[col][row] - '1';
						int idxForMatrix = row / 3 + col / 3 * 3;
						if(colExist[col][num] || rowExist[num][row] || matrixExist[idxForMatrix][num])
							return false;
						colExist[col][num] = rowExist[num][row] = matrixExist[idxForMatrix][num] = true;
					}
				}
			}
			return true;
		}
};
int main(){
}

