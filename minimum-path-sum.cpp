#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
	public:
		int minPathSum(vector<vector<int> >& grid) {
			if(grid.size()==0 || grid[0].size()==0)	return 0;

			int cols = grid.size();
			int rows = grid[0].size();
			vector<vector<int> > dp(2,vector<int>(rows,0));

			dp[0][0] = grid[0][0];
			for(int i=1;i<rows;++i)
				dp[0][i] = dp[0][i-1] + grid[0][i];

			for(int level=1; level< cols;++level){
				dp[level%2][0] = dp[(level-1)%2][0] + grid[level][0];
				for(int idx=1;idx<rows;++idx){
					dp[level%2][idx] = min(dp[(level-1)%2][idx], dp[level%2][idx-1]) + grid[level][idx];
				}
			}
			return dp[(cols-1)%2][rows-1];
		}
};
int main(){
	vector<vector<int> > grid;
	int arr1[3] = {1,3,1};
	int arr2[3] = {1,5,1};
	int arr3[3] = {4,2,1};
	grid.push_back(vector<int>(arr1,arr1+3));
	grid.push_back(vector<int>(arr2,arr2+3));
	grid.push_back(vector<int>(arr3,arr3+3));
	Solution s;
	cout<<s.minPathSum(grid)<<endl;;

}
