#include<iostream>
#include<vector>
#include"print.h"
using namespace std;

class Solution {
	int len;
	public:
		void rotate(vector<vector<int> >& matrix) {
			len = matrix.size();

			int tmp1,tmp2;
			for(int col=0;col<=(len-1)/2;++col){
				if(len-1-col >= col){
					for(int i=col;i<len-1-col;++i){
						tmp1 = matrix[i][len-1-col];
						matrix[i][len-1-col] = matrix[col][i];

						tmp2 = matrix[len-1-col][len-1-i];
						matrix[len-1-col][len-1-i] = tmp1;

						tmp1  = matrix[len-1-i][col];
						matrix[len-1-i][col] = tmp2;

						matrix[col][i] = tmp1;
					}
				}
			}
		}
};

int main(){
	int arr1[4] = {1,2,3,4};
	int arr2[4] = {5,6,7,8};
	int arr3[4] = {9,10,11,12};
	int arr4[4] = {13,14,15,16};
	vector<int> v1(arr1,arr1+4);
	vector<int> v2(arr2,arr2+4);
	vector<int> v3(arr3,arr3+4);
	vector<int> v4(arr4,arr4+4);

	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);

	Solution s;
	Freeman::print(matrix);
	s.rotate(matrix);
	Freeman::print(matrix);
}

