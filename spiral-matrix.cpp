#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	public:
		vector<int> spiralOrder(vector<vector<int> >& matrix) {
			vector<int> res;
			int maxCol = matrix.size();
			if(maxCol == 0 )	return res;
			int maxRow = matrix[0].size();
			if(maxRow == 0)	return res;

			for(int col=0;col <= (maxCol-1)/2;++col){
				if(maxCol-1-col >= col && maxRow-1-col >= col){
					for(int i=col;i<=maxRow-1-col;++i)
						res.push_back(matrix[col][i]);
					for(int i=col+1;i<maxCol-1-col;++i)
						res.push_back(matrix[i][maxRow-1-col]);
					if(maxCol-1-col != col){
						for(int i=maxRow-1-col;i>=col;--i)
							res.push_back(matrix[maxCol-1-col][i]);
					}
					if(col != maxRow-1-col){
						for(int i=maxCol-1-col-1;i>col;--i)
							res.push_back(matrix[i][col]);
					}
				}
			}

			return res;
		}
};
int main(){
	int arr1[4] = {1};
	int arr2[4] = {4};
	int arr3[4] = {7};
	vector<int> v1(arr1,arr1+1);
	vector<int> v2(arr2,arr2+1);
	vector<int> v3(arr3,arr3+1);

	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);

	Solution s;
	vector<int> res = s.spiralOrder(matrix);
	Freeman::print(res);

}
