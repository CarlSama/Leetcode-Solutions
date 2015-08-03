#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	public:
		void setZeroes(vector<vector<int> >& matrix) {
			int cols = matrix.size();
			if(cols==0)	return ;
			int rows = matrix[0].size();
			if(rows==0)	return ;

			bool isColZero=false;
			for(int i=0;i<rows;++i){
				if(matrix[0][i] == 0){
					isColZero = true;	break;
				}
			}
			bool isRowZero = false;
			for(int i=0;i<cols;++i){
				if(matrix[i][0] == 0){
					isRowZero = true;	break;
				}
			}

			for(int i=0;i<cols;++i){
				for(int j=0;j<rows;++j){
					if(matrix[i][j]==0){
						matrix[i][0] = 0;
						matrix[0][j] = 0;
					}
				}
			}

			for(int i=1;i<cols;++i){
				if(matrix[i][0] == 0){
					for(int j=1;j<rows;++j)
						matrix[i][j] = 0;
				}
			}
			for(int i=1;i<rows;++i){
				if(matrix[0][i] == 0){
					for(int j=1;j<cols;++j)
						matrix[j][i] = 0;
				}
			}
			if(isColZero){
				for(int i=0;i<rows;++i)
					matrix[0][i] = 0;
			}
			if(isRowZero){
				for(int i=0;i<cols;++i)
					matrix[i][0] = 0;
			}
		}

		void setZeroes2(vector<vector<int> >& matrix) {
			int cols = matrix.size();
			if(cols==0)	return ;
			int rows = matrix[0].size();
			if(rows==0)	return ;

			vector<bool> colIsZero(cols,false);
			vector<bool> rowIsZero(rows,false);
			for(int i=0;i<cols;++i){
				for(int j=0;j<rows;++j){
					if(matrix[i][j]==0){
						colIsZero[i] = true;
						rowIsZero[j] = true;
					}
				}
			}
			for(int i=0;i<cols;++i){
				if(colIsZero[i] == true){
					for(int j=0;j<rows;++j){
						matrix[i][j] = 0;
					}
				}
			}
			for(int i=0;i<rows;++i){
				if(rowIsZero[i] == true){
					for(int j=0;j<cols;++j){
						matrix[j][i] = 0;
					}
				}
			}
		}
};

int main(){
	int arr1[3] = {1,2,3};
	int arr2[3] = {1,1,1};
	int arr3[3] = {0,1,1};
	vector<int> v1(arr1,arr1+3);
	vector<int> v2(arr2,arr2+3);
	vector<int> v3(arr3,arr3+3);
	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	Solution s;
	s.setZeroes(matrix);
	Freeman::print(matrix);
}
