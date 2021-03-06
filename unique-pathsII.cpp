#include<iostream>
#include<vector>
#include"print.h"

using  namespace std;
class Solution {
	private:
		int cols,rows;
	public:
		/*
		 * let's use memo to avoid TLE
		 * also, sliding arry to avoid MLE
		 */
		int resolve(vector<vector<int> >& grid,vector<vector<int> >&dp,int col,int row){
			if(dp[col][row] != -1)
				return dp[col][row];

			dp[col][row] = 0;
			if(col - 1 >= 0 && !grid[col-1][row])
				dp[col][row] += resolve(grid,dp,col-1,row);
			if(row - 1 >= 0 && !grid[col][row-1])
				dp[col][row] += resolve(grid,dp,col,row-1);

			return dp[col][row];
		}

		int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
			if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0)	return 0;

			cols = obstacleGrid.size();
			rows = obstacleGrid[0].size();
			if(obstacleGrid[0][0] || obstacleGrid[cols-1][rows-1])	return 0;

			vector<vector<int> > dp(cols,vector<int>(rows,-1));
			dp[0][0] = 1;

			resolve(obstacleGrid,dp,cols-1,rows-1);
			return dp[cols-1][rows-1];
		}
};
int main(){
	vector<vector<int> > grid;
	int arr1[3] = {0,0,0};
	int arr2[3] = {0,1,0};
	int arr3[3] = {0,0,0};

	grid.push_back(vector<int>(arr1,arr1+3));
	grid.push_back(vector<int>(arr2,arr2+3));
	grid.push_back(vector<int>(arr3,arr3+3));

	Solution s;
	cout<<s.uniquePathsWithObstacles(grid)<<endl;
}
