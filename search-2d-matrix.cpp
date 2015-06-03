#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		bool searchMatrix(vector<vector<int> >& matrix, int target) {
			int col = matrix.size();
			if(col==0)return false;
			int row = matrix[0].size();

			int top=0,bottom=col-1;
			while(top < bottom){
				int mid = top + (bottom-top)/2;
				if(matrix[mid][row-1]==target)	
					return true;
				else if(matrix[mid][row-1] > target)	
					bottom = mid;
				else	
					top=mid+1;
			}
			int level = top;
			top=0,bottom=row-1;
			while(top <= bottom){
				int mid = top + (bottom - top) / 2;
				if(matrix[level][mid] == target)
					return true;
				else if(matrix[level][mid] > target)
					bottom = mid - 1;
				else 
					top = mid + 1;
			}
			return false;
	}
};
int main(){
	int arr1[4] = {1,3,5,7};
	int arr2[4] = {10,11,16,20};
	int arr3[4] = {23,30,34,50};
	vector<int> v1(arr1,arr1+4);
	vector<int> v2(arr2,arr2+4);
	vector<int> v3(arr3,arr3+4);
	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	Solution s;
	cout<<s.searchMatrix(matrix, 3)<<endl;
	cout<<s.searchMatrix(matrix, 0)<<endl;
	cout<<s.searchMatrix(matrix, 16)<<endl;
	cout<<s.searchMatrix(matrix, 96)<<endl;
}
