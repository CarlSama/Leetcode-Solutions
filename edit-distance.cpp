#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include"print.h"
using namespace std;

class Solution {
	private:
		int len1,len2;
	public:
		int minDistance(string word1, string word2) {
			len1 = word1.size();	len2 = word2.size();
			if(len1==0)	return len2;
			if(len2==0)	return len1;

			vector<vector<int> > dp(len1,vector<int>(len2,INT_MAX));
			dp[0][0] = 1 - (word1[0] == word2[0]);
			for(int i=1;i<len1;++i){
				if(word1[i] == word2[0])
					dp[i][0] = dp[i-1][0];
				else
					dp[i][0] = dp[i-1][0] + 1;
			}
			for(int i=1;i<len2;++i){
				if(word2[i] == word1[0])
					dp[0][i] = dp[0][i-1];
				else
					dp[0][i] = dp[0][i-1] + 1;
			}


			for(int i=1;i<len1;++i){
				for(int j=1;j<len2;++j){
					if(word1[i] == word2[j])
						dp[i][j] = dp[i-1][j-1];
					dp[i][j] = min(dp[i][j], min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1)));
				}
			}
			Freeman::print(dp);			
			return dp[len1-1][len2-1];
		}
};
int main(){
	Solution s;
	cout<<s.minDistance("abcdef","c")<<endl;
}
