#include<iostream>
#include<vector>

using namespace std;

class Solution {
	//1.	使用bool**快于直接使用vector
	//2.	对于有重复性的数据(direct），提取出来做循环以提高代码健壮性
	//３．	
	private:
		int direct[4][2];
		int colums;
		int rows;
	public:
		bool btrack(vector<vector<char> >&board, int x, int y, bool** isUsed, string& word, int curr) {
			if(board[x][y] != word[curr]) return false;
			if(curr+1 == word.size())	return true;

			isUsed[x][y] = true;
			for(int i =0; i< 4; ++ i){
				int xx = x + direct[i][0];
				int yy = y + direct[i][1];

				if(xx>=0 && yy>=0 && xx<colums && yy<rows && !isUsed[xx][yy] ){
					if(btrack(board,xx,yy,isUsed,word,curr+1))
						return true;
				}
			}
			isUsed[x][y] = false;
			return false;
		}

		bool exist(vector<vector<char> >& board, string word) {
			if(board.size()==0 || board[0].size()==0) return false;
			if(word.size()==0) return true;

			direct[0][0] = -1; direct[0][1] = 0;
			direct[1][0] = 1; direct[1][1] = 0;
			direct[2][0] = 0; direct[2][1] = -1;
			direct[3][0] = 0; direct[3][1] = 1;

			colums = board.size();
			rows = board[0].size();

			bool** isUsed = new bool*[colums];
			for(int i=0;i<colums;++i){
				isUsed[i] = new bool[rows];
			}
			for(int i=0;i<colums;++i){
				for(int j=0;j<rows;++j){
					isUsed[i][j] = false;
				}
			}


			for(int i=0;i<colums;++i){
				for(int j=0;j<rows;++j){
					if(btrack(board,i,j,isUsed,word,0))
						return true;
				}
			}
			return false;
		}
};

int main(){
	vector<char> v1;
	v1.push_back('a');
	/*v1.push_back('A'); v1.push_back('B'); v1.push_back('C');v1.push_back('E');
	vector<char> v2;
	v2.push_back('S'); v2.push_back('F'); v2.push_back('C');v2.push_back('S');
	vector<char> v3;
	v3.push_back('A'); v3.push_back('D'); v3.push_back('E');v3.push_back('E');
	*/

	vector<vector<char> > v;
//	v.push_back(v1); v.push_back(v2); v.push_back(v3);
	v.push_back(v1);

	Solution s;
	cout<<s.exist(v,"a")<<endl;
	cout<<s.exist(v,"SEE")<<endl;
	cout<<s.exist(v,"ABCB")<<endl;

}


