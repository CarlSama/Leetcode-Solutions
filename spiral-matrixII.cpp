#include<iostream>
#include"print.h"
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<int> > generateMatrix(int n) {
			if(n==0)	return vector<vector<int> >();
			vector<vector<int> > res(n,vector<int>(n,0));
			int number = 0;
			for(int col=0;col <= (n-1)/2;++col){
				if(n-1-col >= col){
					for(int i=col;i<=n-1-col;++i)
						res[col][i] = ++number; 
					for(int i=col+1;i<n-1-col;++i)
						res[i][n-1-col] = ++number;
					if(n-1-col != col){
						for(int i=n-1-col;i>=col;--i)
							res[n-1-col][i] = ++number;
					}
					if(n-1-col != col){
						for(int i=n-1-col-1;i>col;--i)
							res[i][col] = ++number;
					}
				}
			}
			return res;
		}
};
int main(){
	Solution s;
	vector<vector<int> > res = s.generateMatrix(3);
	Freeman::print(res);
}
