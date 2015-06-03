#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
	private:
		int cols,rows;
	public:
		int calculateMinimumHP(vector<vector<int> >& dungeon) {
			if(dungeon.size()==0 || dungeon[0].size()==0)	return 0;
			cols = dungeon.size();	rows = dungeon[0].size();
			vector<vector<int> > dp(cols,vector<int>(rows,0));
			dp[cols-1][rows-1] = max(1 - dungeon[cols-1][rows-1],1);
			for(int i = cols-2;i>=0;--i)
				dp[i][rows-1] = max(dp[i+1][rows-1] - dungeon[i][rows-1], 1);
			for(int i = rows-2;i>=0;--i)
				dp[cols-1][i] = max(dp[cols-1][i+1] - dungeon[cols-1][i], 1);
			for(int i = cols-2;i>=0;--i){
				for(int j=rows-2;j>=0;--j){
					dp[i][j]=min(max(dp[i+1][j]-dungeon[i][j],1),max(dp[i][j+1]-dungeon[i][j],1));
				}
			}
			return dp[0][0];
		}
};
int main(){
	int arr0[3] = {-2,-3,3};
	int arr1[3] = {-5,-10,1};
	int arr2[3] = {10,30,-5};
	vector<vector<int> > dungeon;
	dungeon.push_back(vector<int>(arr0,arr0+3));
	dungeon.push_back(vector<int>(arr1,arr1+3));
	dungeon.push_back(vector<int>(arr2,arr2+3));
	Solution s;
	cout<<s.calculateMinimumHP(dungeon)<<endl;
}
