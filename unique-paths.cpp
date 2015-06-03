#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		int uniquePaths(int m, int n) {
			vector<vector<int> > dp(m,vector<int>(n,0));

			for(int i=0;i<n;++i)
				dp[0][i] = 1;

			for(int i=1;i<m;++i){
				for(int j=0;j<n;++j){
					dp[i][j] = dp[i-1][j];
					if(j > 0)
						dp[i][j] += dp[i][j-1];
				}
			}
			return dp[m-1][n-1];
		}
};
int main(){
	Solution s;
	cout<<s.uniquePaths(3,2);
}
